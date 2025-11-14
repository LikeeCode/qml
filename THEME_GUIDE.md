# Theme System Usage Guide

## Overview
The application uses a singleton Theme object that provides centralized color management and supports switching between Day/Night modes.

## How to Use

### 1. Import the Theme
Add this import to any QML file:
```qml
import "../theme"  // Adjust path based on your file location
// OR from root level:
import "theme"
```

### 2. Use Theme Colors
Replace hardcoded colors with Theme properties:

**Before:**
```qml
Rectangle {
    color: '#373647'
    border.color: '#4a4a64'
}

Text {
    color: '#ffffff'
}
```

**After:**
```qml
Rectangle {
    color: Theme.panelBackground
    border.color: Theme.panelBorder
}

Text {
    color: Theme.textPrimary
}
```

### 3. Available Theme Properties

#### Background Colors
- `Theme.backgroundColor` - Main window background
- `Theme.panelBackground` - Panel/card backgrounds
- `Theme.panelBorder` - Border colors

#### Item Colors (for lists, delegates)
- `Theme.itemBackground1` - First alternating row
- `Theme.itemBackground2` - Second alternating row
- `Theme.itemBackgroundActive` - Active/selected item
- `Theme.itemBackgroundHover` - Hovered item
- `Theme.itemBackgroundPressed` - Pressed item

#### Text Colors
- `Theme.textPrimary` - Main text
- `Theme.textSecondary` - Secondary text
- `Theme.textTertiary` - Subtle/disabled text

#### Icon Colors
- `Theme.iconNormal` - Default icon color
- `Theme.iconHover` - Hovered icon
- `Theme.iconPressed` - Pressed icon

#### Accent Colors
- `Theme.accentColor` - Accent/highlight color
- `Theme.errorColor` - Error states
- `Theme.successColor` - Success states

### 4. Toggle Theme
Call the toggle function from anywhere:
```qml
Button {
    text: Theme.isDarkMode ? "☀️ Light Mode" : "🌙 Dark Mode"
    onClicked: Theme.toggleTheme()
}
```

### 5. Check Current Mode
```qml
property bool isDark: Theme.isDarkMode

// Conditional behavior based on theme
Image {
    source: Theme.isDarkMode ? "icon-dark.png" : "icon-light.png"
}
```

## Example: Converting a Component

### Original Component
```qml
import QtQuick

Rectangle {
    color: '#444466'
    
    Text {
        text: "Hello"
        color: '#ffffff'
    }
    
    MouseArea {
        onEntered: parent.color = '#555577'
        onExited: parent.color = '#444466'
    }
}
```

### Theme-Enabled Component
```qml
import QtQuick
import "../theme"

Rectangle {
    color: Theme.itemBackground1
    
    Text {
        text: "Hello"
        color: Theme.textPrimary
    }
    
    MouseArea {
        onEntered: parent.color = Theme.itemBackgroundHover
        onExited: parent.color = Theme.itemBackground1
    }
}
```

## Benefits
1. **Consistent colors** across the entire app
2. **Easy theme switching** - toggle between day/night instantly
3. **Centralized maintenance** - change colors in one place
4. **Automatic updates** - all components update when theme changes
5. **No hardcoded colors** - easier to add new themes later

## Adding New Colors
Edit `theme/Theme.qml`:
```qml
readonly property color myNewColor: isDarkMode ? "#darkValue" : "#lightValue"
```

Then use it anywhere:
```qml
Rectangle { color: Theme.myNewColor }
```
