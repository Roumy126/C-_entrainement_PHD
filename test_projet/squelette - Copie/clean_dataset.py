import json

with open("dataset.json", "r") as f:
    lines = f.readlines()

cleaned = []
for line in lines:
    line = line.strip()
    if not line:
        continue  # ignorer les lignes vides
    try:
        json.loads(line)
        cleaned.append(line)
    except json.JSONDecodeError:
        print("❌ Ligne ignorée (invalide):", line)

with open("dataset.json", "w") as f:
    f.write("\n".join(cleaned) + "\n")

print("✅ Fichier dataset.json nettoyé.")
