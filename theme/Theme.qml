pragma Singleton
import QtQuick

QtObject {
    id: root
    
    // Theme mode property
    property bool isDarkMode: true
    
    // Background colors
    readonly property color backgroundColor: isDarkMode ? "#363636" : "#f5f5f5"
    readonly property color panelBackground: isDarkMode ? "#373647" : "#ffffff"
    readonly property color panelBorder: isDarkMode ? "#4a4a64" : "#cccccc"
    
    // Item colors (alternating rows)
    readonly property color itemBackground1: isDarkMode ? "#444466" : "#f9f9f9"
    readonly property color itemBackground2: isDarkMode ? "#3b3b5b" : "#efefef"
    readonly property color itemBackgroundActive: isDarkMode ? "#7777a8" : "#4a90e2"
    readonly property color itemBackgroundHover: isDarkMode ? "#555577" : "#e0e0e0"
    readonly property color itemBackgroundPressed: isDarkMode ? "#222244" : "#c0c0c0"
    
    // Text colors
    readonly property color textPrimary: isDarkMode ? "#ffffff" : "#333333"
    readonly property color textSecondary: isDarkMode ? "#cccccc" : "#666666"
    readonly property color textTertiary: isDarkMode ? "#bebebe" : "#999999"
    
    // Button/Icon colors
    readonly property color iconNormal: isDarkMode ? "#ffffff" : "#333333"
    readonly property color iconHover: isDarkMode ? "#cccccc" : "#666666"
    readonly property color iconPressed: isDarkMode ? "#999999" : "#999999"
    
    // Accent colors (same for both themes)
    readonly property color accentColor: "#4a90e2"
    readonly property color errorColor: "#e74c3c"
    readonly property color successColor: "#2ecc71"
    
    // Function to toggle theme
    function toggleTheme() {
        isDarkMode = !isDarkMode
    }
}
