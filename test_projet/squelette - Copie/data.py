import json
import random

def generate_fake_entry(player):
    board = []
    for _ in range(9):  # 3x3
        owner = random.choice([0, 1, 2])  # 0: NO_PLAYER, 1: PLAYER_1, 2: PLAYER_2
        size = random.choice([0, 1, 2, 3])
        board.extend([owner, size])

    action_type = random.choice(["place", "move"])
    if action_type == "place":
        size = random.choice([1, 2, 3])
        from_pos = [-1, -1]
        to_pos = [random.randint(0, 2), random.randint(0, 2)]
    else:
        size = -1
        from_pos = [random.randint(0, 2), random.randint(0, 2)]
        to_pos = [random.randint(0, 2), random.randint(0, 2)]

    entry = {
        "player": player,
        "board": board,
        "action": {
            "type": action_type,
            "size": size,
            "from": from_pos,
            "to": to_pos
        }
    }
    return entry

dataset = [generate_fake_entry(player=random.choice([1, 2])) for _ in range(100)]

with open("dataset.json", "w") as f:
    for entry in dataset:
        f.write(json.dumps(entry) + "\n")
