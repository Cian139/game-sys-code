# SEN400G-WXWidgets #

Template repository with support for [wxWidgets](https://www.wxwidgets.org/) (Windows only). 

## Setup ##

After cloning the repository, you'll need to download ```wxwidgets-src.zip``` from Moodle (or via this [link](https://outlookuwicac-my.sharepoint.com/:u:/g/personal/sm22341_cardiffmet_ac_uk/EXXGXvxk21FMl_-xTq3xnmYBiaqQT6IAFmEKW3YTM-fToA?e=HDKnUP)) and unzip this file in ```SEN400G_Assignment``` (top level of the solution). The paths for Additional Include and Additional library files within the solution are setup for the following!

```bash 
SEN400G-wxWidgets
└── SEN400G_Assignment
    ├── Backend
    ├── ConsoleApplication1
    ├── Frontend
    └── wxwidgets-src
        ├── include
        │   ├── ...
        └── lib
            └── ...
```

Sadly ```wxwidgets-src``` contains files too large for a normal GitHub repository, the solution LFS (Large File Storage) doesn't work with Github Classroom Templates.  

## About the Code ##

The Visual Studio Solution contains 3 projects;

| Project Name | Includes / Depends on | Notes |
| :-- | :-: | :-- | 
| Backend | None |A library (no ```main()```) this is used by other projects and will provide the file handling and classes represent the elements of the file. |
| Frontend | Backend | Produces an executable, this project is linked with [wxWidgets](https://www.wxwidgets.org/) allowing the production of a simple GUI. |
| Testing | Backend | This project also creates an executable, this is console application which can be used to test the classes developed as part of the backend library |

## Testing ##

| Operating System | IDE | Status |
| :-- | :-- | :-: |
| Windows 10 | Visual Studio 2022 | **WORKS** |
| Windows 11 | Visual Studio 2022 | **WORKS** |
