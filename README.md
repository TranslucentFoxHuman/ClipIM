This has been translated into English by AI from Japanese. Please refer to README-JA.md for the original text.

# ClipIM
Software that displays a dialog with an input field to copy text to the clipboard.

# What is this?
Some software that does not support multi-byte text input via input methods may still support pasting from the clipboard.  
When this software is launched, it displays a dialog with a text input field. By pressing a button on the screen or the Enter (or Ctrl+Enter) key, the entered text is saved to the clipboard and the program exits.  
By using this, you can quickly copy the input result to the clipboard and paste the text into software that does not support input via IM.

Additionally, it can be used for purposes other than this, such as a temporary draft before sending an instant message.

This software was developed by a Japanese developer who was frustrated by encountering software that does not allow direct Japanese input using IME. While it mainly focuses on Japanese input, it should work for any language that requires input via an input method, such as Chinese or Korean! Of course, it will also function adequately for languages like English that do not require an input method for drafting.

# How to use
## Basic
In the Single line tab, you can input a single line of text. After entering, pressing the Enter key will copy the content to the clipboard and exit.  
In the Multi line tab, you can input multiple lines of text. Here, pressing the Ctrl+Enter key will copy the content to the clipboard and exit.

Pressing the Cancel button will exit without copying anything.  
Pressing the Copy button will copy the content to the clipboard but will not exit.  
Pressing the Copy and Close button will copy the content to the clipboard and exit.

## Command Line Options
- -s : Launches in Single line input mode.
- -m : Launches in Multi line input mode.
- -h : Outputs help to the console.
- -v : Outputs version information to the console.

## Convenient Usage
This software does not capture shortcut keys by itself. It is designed to be registered in the shortcut key settings of your desktop environment.  
For example, you can assign "```clipim -s```" to Win+Insert and "```clipim -m```" to Win+Shift+Insert, but it is up to you which keys to assign to which commands.

# Build Instructions
## Required Packages
### Debian-based Systems
To build this project on a Debian-based system, install the following:
- cmake
- build-essential
- qtbase5-dev or qt6-base-dev

You can install these packages by running the following command:  
```sudo apt install cmake build-essential qtbase5-dev```

### Fedora
To build this project on Fedora, install the following:
- The group: c-development
- cmake
- qt5-qtbase-devel or qt6-qtbase-devel

You can install these packages by running the following command:  
```
sudo dnf group install c-development
sudo dnf install cmake qt5-qtbase-devel
```

### Arch Linux
To build this project on Fedora, install the following:
- base-devel
- cmake
- qt5-base or qt6-base

You can install these packages by running the following command:  
```
sudo pacman -S base-devel cmake qt5-base
```


## Build
To build, navigate to the folder containing this project and execute the following commands in order:
```
mkdir build
cd build
cmake ../
make -j$(nproc)
```
Optionally, you can install this software on your system with the following command:  
```
sudo make install
```