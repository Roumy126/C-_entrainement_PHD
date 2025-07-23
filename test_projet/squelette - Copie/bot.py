import torch
import torch.nn as nn
import json
import random

class GobbletBot(nn.Module):
    def __init__(self):
        super().__init__()
        self.shared = nn.Sequential(
            nn.Linear(3 * 3 * 2 + 1, 64),
            nn.ReLU(),
            nn.Linear(64, 32),
            nn.ReLU()
        )
        self.action_type = nn.Linear(32, 2)  # 0=place, 1=move
        self.from_head = nn.Linear(32, 10)   # 0-8 positions, 9 = none
        self.to_head = nn.Linear(32, 9)      # 0-8 positions

    def forward(self, x):
        features = self.shared(x)
        return self.action_type(features), self.from_head(features), self.to_head(features)

def choose_size():
    return random.choice([1, 2, 3])  # Tu peux rendre ça plus intelligent

def predict(model, board_flat, player):
    x = torch.tensor(board_flat + [player], dtype=torch.float32).unsqueeze(0)
    with torch.no_grad():
        action_logits, from_logits, to_logits = model(x)
        action_type = torch.argmax(action_logits).item()
        from_index = torch.argmax(from_logits).item()
        to_index = torch.argmax(to_logits).item()

    move_type = "place" if action_type == 0 else "move"
    move = {
        "type": move_type,
        "size": choose_size() if move_type == "place" else -1,
        "from": [-1, -1] if move_type == "place" else [from_index // 3, from_index % 3],
        "to": [to_index // 3, to_index % 3]
    }
    return move

def generate_bot_move():
    with open("dataset.json", "r") as f:
        data = json.loads(f.readlines()[-1])
    player = data["player"]
    board_flat = data["board"]
    model = GobbletBot()
    model.load_state_dict(torch.load("bot_model.pt", weights_only=True))
    model.eval()
    move = predict(model, board_flat, player)
    with open("bot_output.json", "w") as f:
        json.dump(move, f, indent=2)

if __name__ == "__main__":
    generate_bot_move()
