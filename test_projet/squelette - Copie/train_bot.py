import torch
import torch.nn as nn
import json

# Modèle du bot
class GobbletBot(nn.Module):
    def __init__(self):
        super().__init__()
        self.shared = nn.Sequential(
            nn.Linear(3 * 3 * 2 + 1, 64),
            nn.ReLU(),
            nn.Linear(64, 32),
            nn.ReLU()
        )
        self.action_type = nn.Linear(32, 2)   # 0=place, 1=move
        self.from_head = nn.Linear(32, 10)    # 0-8 ou 9 (none)
        self.to_head = nn.Linear(32, 9)       # 0-8

    def forward(self, x):
        features = self.shared(x)
        return self.action_type(features), self.from_head(features), self.to_head(features)

# Chargement depuis un tableau JSON
def load_dataset(file_path):
    X, y_action, y_from, y_to = [], [], [], []
    with open(file_path, 'r') as f:
        data_list = json.load(f)  # lecture du tableau JSON

    for data in data_list:
        features = data["board"] + [data["player"]]
        X.append(features)

        action = data["action"]
        y_action.append(0 if action["type"] == "place" else 1)

        if action["type"] == "place":
            y_from.append(9)
        else:
            y_from.append(action["from"][0] * 3 + action["from"][1])

        y_to.append(action["to"][0] * 3 + action["to"][1])

    return (torch.tensor(X, dtype=torch.float32),
            torch.tensor(y_action, dtype=torch.long),
            torch.tensor(y_from, dtype=torch.long),
            torch.tensor(y_to, dtype=torch.long))

# Entraînement du modèle
X, y_action, y_from, y_to = load_dataset("dataset.json")
model = GobbletBot()
optimizer = torch.optim.Adam(model.parameters(), lr=0.001)
loss_fn = nn.CrossEntropyLoss()

for epoch in range(100):
    model.train()
    optimizer.zero_grad()
    out_action, out_from, out_to = model(X)
    loss = (loss_fn(out_action, y_action) +
            loss_fn(out_from, y_from) +
            loss_fn(out_to, y_to))
    loss.backward()
    optimizer.step()
    print(f"Epoch {epoch+1} - Loss: {loss.item():.4f}")

# Sauvegarde
torch.save(model.state_dict(), "bot_model.pt")
