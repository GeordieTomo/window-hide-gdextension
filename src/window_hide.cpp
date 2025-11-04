#include "window_hide.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/display_server.hpp>

using namespace godot;

WindowHide::WindowHide() {
}

WindowHide::~WindowHide() {
}

void WindowHide::hide_window() {
#ifdef _WIN32
    HWND main_hwnd = (HWND)DisplayServer::get_singleton()->window_get_native_handle(
        DisplayServer::WINDOW_HANDLE, 0);
    if (main_hwnd) {
        ShowWindow(main_hwnd, SW_HIDE);
    }
#endif
}

void WindowHide::show_window() {
#ifdef _WIN32
    HWND main_hwnd = (HWND)DisplayServer::get_singleton()->window_get_native_handle(
        DisplayServer::WINDOW_HANDLE, 0);
    if (main_hwnd) {
        // Restore if minimized
        if (IsIconic(main_hwnd)) {
            ShowWindow(main_hwnd, SW_RESTORE);
        } else {
            ShowWindow(main_hwnd, SW_SHOW);
        }
        
        // Bring window to foreground and set focus
        SetForegroundWindow(main_hwnd);
        SetFocus(main_hwnd);
        
        // Flash window if it doesn't get focus
        if (GetForegroundWindow() != main_hwnd) {
            FlashWindow(main_hwnd, TRUE);
        }
    }
#endif
}

bool WindowHide::is_window_visible() {
#ifdef _WIN32
    HWND main_hwnd = (HWND)DisplayServer::get_singleton()->window_get_native_handle(
        DisplayServer::WINDOW_HANDLE, 0);
    if (main_hwnd) {
        return IsWindowVisible(main_hwnd) && !IsIconic(main_hwnd);
    }
#endif
    return false;
}

void WindowHide::_bind_methods() {
    ClassDB::bind_static_method("WindowHide", D_METHOD("hide_window"), &WindowHide::hide_window);
    ClassDB::bind_static_method("WindowHide", D_METHOD("show_window"), &WindowHide::show_window);
    ClassDB::bind_static_method("WindowHide", D_METHOD("is_window_visible"), &WindowHide::is_window_visible);
}