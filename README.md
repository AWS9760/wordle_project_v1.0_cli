# 🎯 Wordle CLI (v1.0)

A simple and fun **Command-Line Wordle game** built in C++. This project replicates the popular Wordle gameplay in a terminal environment with clear logic, interactive feedback, and replay support.

---

## 📌 Features

- 🎮 Classic Wordle gameplay (guess the hidden word)
- 🔤 Input validation for correct word length
- 🟩🟨⬜ Feedback system:
  - 🟩 Correct letter & position
  - 🟨 Correct letter, wrong position
  - ⬜ Incorrect letter
- 🔁 Replay option after each game
- ⚡ Lightweight and fast (CLI-based)
- 🧠 Clean implementation using OOP concepts

---

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:**
  - Object-Oriented Programming (OOP)
  - String manipulation
  - Conditional logic
  - Loops & control flow

---

## 🚀 How to Run

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/wordle_project_v1.0_cli.git
cd wordle_project_v1.0_cli
```
2. Compile the Code
```bash
g++ wordle.cpp -o wordle
```
3. Run the Game
```bash
./wordle
```
🎯 How to Play
Guess the hidden word within limited attempts.
After each guess, you’ll get feedback:
🟩 Letter is correct and in the correct position
🟨 Letter is correct but in the wrong position
⬜ Letter is not in the word
Use the hints to improve your next guess.
Win by guessing the word correctly!
📂 Project Structure
```bash
wordle_project_v1.0_cli/
│── wordle.cpp     # Main game source code
│── README.md      # Project documentation
```
💡 Future Improvements
Add difficulty levels
Load words from a file/dictionary
Add color output for better UI
Track score/history
