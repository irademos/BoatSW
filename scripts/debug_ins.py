import json

def load_config(file_path):
    with open(file_path, 'r') as f:
        return json.load(f)

if __name__ == "__main__":
    config = load_config("../config/boat_config.json")
    print("Loaded configuration:", config)
