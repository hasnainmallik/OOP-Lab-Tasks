```markdown
# VS Code Workspace Settings

## Overview
This repository contains a Visual Studio Code workspace configuration file that controls Makefile extension behavior.

## File Structure
```
.vscode/
└── settings.json
```

## Configuration Details

### Settings File
**File**: `settings.json`  
**Location**: `.vscode/settings.json`  
**Purpose**: Workspace-specific VS Code settings

### Current Configuration
```json
{
    "makefile.configureOnOpen": false
}
```

## What This Setting Does

### Functionality
- **Disables automatic Makefile configuration** when opening the workspace
- **Prevents auto-detection** of build systems on startup
- **Requires manual configuration** of Makefile extension when needed

### Benefits
- **Faster workspace loading** - skips automatic configuration phase
- **Reduced overhead** for large projects with complex build systems
- **Manual control** over when Makefile configuration occurs
- **Prevents unwanted automatic builds** on project open

## Usage Instructions

### For This Workspace
1. Open the project in VS Code
2. The Makefile extension will not auto-configure
3. Configure Makefile settings manually when required

### Manual Configuration (When Needed)
1. Open Command Palette (`Ctrl+Shift+P`)
2. Run: `Makefile: Configure`
3. Follow the extension prompts

## When to Use This Setting

### Recommended For
- Large projects with complex build systems
- Projects where automatic configuration is slow
- Environments where manual build control is preferred
- Workspaces with multiple build configurations

### Not Recommended For
- Small projects with simple Makefiles
- When automatic detection is desired
- Beginner developers unfamiliar with manual configuration

## Extension Requirements
- Requires the "Makefile Tools" extension from Microsoft
- Compatible with VS Code version 1.30.0+

## Related Documentation
- [VS Code Settings](https://code.visualstudio.com/docs/getstarted/settings)
- [Makefile Tools Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools)
```

This README provides:
- Clear hierarchical structure with headers
- Code blocks for configuration content
- Bullet points for easy scanning
- Usage scenarios and recommendations
- Technical requirements and references
- Professional formatting suitable for development teamsile in your `.vscode` folder for workspace-specific settings.
```
