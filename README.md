# FunctionalRPG
A small expansion on my basic 'rpg' style c++ practice, now using multiple functions.

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/Yuugen64/004_CleanMem/README.md">
    <img src="003_C++_Sprite.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">C++ RPG with Functions</h3>
  
  <br />
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)




<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->


### Built With
* C++



<!-- GETTING STARTED -->
## Getting Started

Download the .zip. If on windows, you can run the executable, otherwise you will have to compile it for your system.



### Prerequisites

```sh
No prerequisites.
```

### Installation

1. Click the green download button to get the .zip!



<!-- USAGE EXAMPLES -->
## Usage
- Exploring C++ some more.

<!-- CHANGELOG -->
## Changelog:
<!-- DATES and what changed/was accomplished on that day. -->

4.3.21
- Created the repo.
- [001-0.0.1]:: INITIAL COMMIT >> Updated README and added core cpp file.
- [002-0.0.2]:: Code Addition >> Added the ability to get players name and select a class. Will expand validation next time.

4.4.21
- Created new branch.
- Learned to compile C++ on Mac.
- Ran into an issue with the following error:

```sh
warning: unable to access '/Users/yuugen64/.config/git/ignore': Permission denied
```

SOLUTION:
```sh
1. In Terminal cd to the User director with cd ~.
2. Change the directory permissions with sudo chmod 755 .config
3. Enter your login password.
```
--> Solved by MeltingDog via StackOverflow.

As far as I can tell, this issue is due to some kind of conflict where the root account on my Mac (i.e. my administrator account since I own the computer) sets certain permissions as it goes along. Meaning, that when I try to manipulate my git repository locally on a different branch, the new branch somehow lacks the correct permissions to do so? Leaving this fix here for the future.

(For context, this occured AFTER I successfully cloned the git repo to my desktop. Opened the project in VS Code, and compiled the .cpp file into an executable for Mac using clang++. When trying to execute < git add . >, the error came up.

- [003-9.9.3]:: NEW branch - MacFunctionalRPG >> Cloned the project on my Mac, and thus created a new branch to differentiate that point in time


### Main Branch:
- Where the core project is located.

<!-- CONTRIBUTING -->
## Contributing

For this particular project, there have been no outside contributions. If that changes in the future I will be sure to update this section to accurately credit those authors.



<!-- CONTACT -->
## Contact

Yuugen64@protonmail.com

<!-- ***Make sure to update REPO in BOTH URLs here*** -->
Project Link: [https://github.com/Yuugen64/FunctionalRPG](https://github.com/Yuugen64/FunctionalRPG)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Othneildrew](https://github.com/othneildrew/Best-README-Template/blob/master/README.md) - For providing a great template for leveling up my README!
* [Abdul Bari](https://www.udemy.com/course/cpp-deep-dive/) - Lecturer in the Udemy course I am following to learn this material.

