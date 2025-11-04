# Window Hide GDExtension

A simple GDExtension for Godot 4.x that provides window hiding functionality on Windows. Perfect for creating applications that can hide to the system tray or run in the background.

## Prerequisites

- Python 3.6+
- SCons build system: `pip install scons`
- Visual Studio 2019 or later (for Windows compilation)
- Git
- Godot 4.1+ (tested with 4.5)

## Building the Extension

### 1. Clone godot-cpp

```bash
cd window-hide-extension
git clone https://github.com/godotengine/godot-cpp.git
cd godot-cpp
git checkout 4.5  # Use the version matching your Godot version
cd ..
```

### 2. Build godot-cpp

**Debug build:**
```bash
cd godot-cpp

scons platform=windows target=template_debug
```

**Release build:**
```bash
scons platform=windows target=template_release
```

This will take several minutes. The compiled libraries will be in `godot-cpp/bin/`.

### 3. Build the Extension

**Debug build:**
```bash
cd window-hide-extension

scons platform=windows target=template_debug
```

**Release build:**
```bash
scons platform=windows target=template_release
```

The compiled DLL will be created in `demo/bin/`.

## Installation

### File Structure

Place these files in your Godot project:

```
your_godot_project/
└── window_hide/
│    ├── window_hide.gdextension
│    └── bin/
│        ├── libwindow_hide.windows.template_debug.x86_64.dll
│        └── libwindow_hide.windows.template_release.x86_64.dll
└── main.gd
```

## API Reference

All functions are static - call them directly without creating an instance.

### Methods

| Method | Description |
|--------|-------------|
| `WindowHide.hide_window()` | Hides the main window |
| `WindowHide.show_window()` | Shows window, restores if minimized, grabs focus |
| `WindowHide.is_window_visible()` | Returns `true` if window is visible and not minimized |

## Usage Examples

### Toggle Window Visibility

```gdscript
extends Node

func toggle_window():
    if WindowHide.is_window_visible():
        WindowHide.hide_window()
    else:
        WindowHide.show_window()
```

### Integration with System Tray (using StatusIndicator)

```gdscript
extends StatusIndicator

func _ready():
    # When tray icon is clicked, toggle window visibility
    pressed.connect(toggle_window.unbind(2))
    
    # Optional: Hide window on startup
    # WindowHide.hide_window()

func toggle_window():
    if WindowHide.is_window_visible():
        WindowHide.hide_window()
    else:
        WindowHide.show_window()
```
