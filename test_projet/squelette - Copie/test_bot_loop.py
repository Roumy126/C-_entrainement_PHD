import subprocess
import time
import json

print("🔁 Test du bot sur les 10 derniers états du dataset...\n")

with open("dataset.json", "r") as f:
    lines = f.readlines()[-10:]

for i, line in enumerate(lines):
    with open("dataset.json", "w") as f:
        f.write(line)
    subprocess.run(["python", "bot.py"])
    with open("bot_output.json") as f:
        result = json.load(f)
    print(f"Test {i+1} => Action prédite : {result}")
    time.sleep(0.5)
