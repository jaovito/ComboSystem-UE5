Here's the translated README for the Unreal Engine Combo System:

---

# Unreal Engine Combo System

This project is a combo system developed in Unreal Engine, designed for action games that require a fluid and dynamic sequence attack mechanic. It allows creating and configuring custom combos for characters, as well as offering flexibility to add new animations and combo conditions.

## 📋 Features

- **Customizable Combo Creation:** Configure sequences of attacks, moves, or abilities, defining the timing and animations of each action.
- **Input Detection:** Accurately detects player input for continuous combo execution.
- **Action Canceling:** Allows canceling actions to add fluidity and responsiveness to the system.
- **Visual Feedback:** VFX on the sword slashes animation

## 🛠 Project Structure

- **Blueprints and C++:** The system was developed with a combination of Blueprints and C++ to ensure efficiency and flexibility.
- **Reusable Components:** The system is modular and can be added to any character in Unreal Engine.
- **Playable Example:** The project includes an example character to test the combo system (Aurora character).
- **C++ logic:** The combat system was created with C++, so, the variables and functions that make the character hit and slash, was made in C++ and can be used in blueprints.

## 🚀 How to Use

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/usuario/UnrealEngineComboSystem.git
   ```
2. **Open the Project in Unreal Engine:**
   Open Unreal Engine, go to **File > Open Project** and select the `.uproject` file.

3. **Character Integration:**
   - Add your character to the BP_ThirdPersonCharacter.
   - Configure the animations and combo conditions in the component’s and Class properties (inside the blueprint).
   - If you want, you can create a new blueprint character and use the base C++ class called `SoulsLikeCharacter`.

4. **Animation and Input Setup:**
   - In the Unreal Editor, configure the desired animations and inputs for combos.
   - The animations need to have the Anim Notifiers, they are inside `Player/Blueprints/Notifiers` and `ThirdPerson/Blueprint`.
   - You can follow the example on anim montages inside `Player/Animations/Aurora/Montages`.
   - Test the system in **Play Mode** to check the fluidity and timing of the combos.

## 🛠 Technologies Used

- **Unreal Engine 5**
- **C++ / Blueprints**
- **Customizable animations for combos**

## 🎮 Demo

https://github.com/user-attachments/assets/3c6012f3-f627-4bef-8aec-8ce288e410d3

## 📝 Final Notes

This combo system was developed with a focus on expansion and customization. Feel free to modify and adapt it according to your game’s needs!

---

**Developed by [jaovito](https://github.com/jaovito)**  
[LinkedIn](https://www.linkedin.com/in/jo%C3%A3o-vit%C3%B3rio-1420a117b/) | [GitHub](https://github.com/jaovito)

---

This encapsulates all content within the markdown code block.
