# 🎵 Music Management System (C++)

## 📘 Overview
The **Music Management System** is a **console-based application** built using **Object-Oriented Programming (OOP)** in C++.  
It allows users to **store, manage, and search** their favorite songs efficiently.  
All song data can be **saved to** and **loaded from** a text file, ensuring data persistence between sessions.

---

## 🧩 Features
✅ Add new songs with details (title, artist, album, genre, duration)  
✅ Display all songs stored in the library  
✅ Search for a song by title  
✅ Delete songs using their unique ID  
✅ Save and load songs to/from a file  
✅ Simple menu-based interface  

---

## ⚙️ OOP Concepts Used
| Concept | Description |
|----------|--------------|
| **Class & Object** | The program defines two main classes — `Song` and `Library`. Each song is an object of the `Song` class. |
| **Encapsulation** | Data members (like title, artist, duration) are private and accessed through public getters and methods. |
| **Abstraction** | The internal details of file handling and vector operations are hidden from the user. |
| **Composition** | The `Library` class contains multiple `Song` objects using a `vector<Song>`. |
| **File Handling** | The system reads and writes song data to a text file (`songs.txt`) for persistence. |

---

## 🏗️ Class Design

### **Class Song**
Handles individual song data and formatting.
```cpp
class Song {
private:
    int id;
    string title, artist, album, genre;
    double duration;
public:
    void display() const;
    string toFileFormat() const;
    int getId() const;
    string getTitle() const;
};
```

### **Class Library**
Manages a collection of songs and user operations.
```cpp
class Library {
private:
    vector<Song> songs;
    int nextId;
public:
    void addSong();
    void displayAll() const;
    void searchByTitle() const;
    void removeSong();
    void saveToFile(const string &filename) const;
    void loadFromFile(const string &filename);
};
```

---

## 🖥️ Program Flow
```
Start
↓
Load songs from file (songs.txt)
↓
Display menu:
1. Add Song
2. View All Songs
3. Search Song by Title
4. Delete Song
5. Save Library
6. Exit
↓
Perform selected action
↓
Loop until user exits
↓
End
```

---

## 📂 File Structure
```
/MusicManagementSystem
│
├── main.cpp          → Main source code
├── songs.txt         → Data file storing songs
└── README.md         → Project documentation
```

---

## 🧠 Example of Data Saved (songs.txt)
```
1|Jatt Fire Karda|Diljit Dosanjh|Illuminati|Punjabi Pop|2.50
2|Kharku|Diljit Dosanjh|Back to Basics|Bhangra|3.85
3|Big Shot|Tarsem Jassar|Turbanator|Punjabi Hip-Hop|3.92
```

---

## 🧰 Requirements
- **Compiler:** GCC / MinGW / Turbo C++ (C++11 or later)
- **OS:** Windows, Linux, or macOS
- **Editor:** Any IDE or text editor (VS Code, Code::Blocks, Dev-C++)

---

## 🚀 How to Run
1. Clone or download the project.  
2. Open terminal or IDE.  
3. Compile the file:
   ```bash
   g++ main.cpp -o music
   ```
4. Run the executable:
   ```bash
   ./music
   ```
5. Follow the on-screen menu to manage songs.

---

## 📊 Future Enhancements
- Add playlist feature  
- Sort songs by artist, album, or duration  
- Add a graphical user interface (GUI)  
- Use database (SQLite/MySQL) instead of text files  

---

## 👨‍💻 Author
**Jatinder Singh**  
A passionate developer exploring C++, Python, and data-driven systems.  
