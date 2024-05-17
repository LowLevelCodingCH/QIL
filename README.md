<a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/LowLevelCodingCH/QIL">
    <img src="QIL.png" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">QIL or Quill</h3>

  <p align="center">
    A simple IR for making building programming languages easier
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

There are many IRs out there, but none of them were good for me, or they just straight-up didn't work, so here's what i got:

Here's why:
* This IR is easy to read and write, yet still is easy to lex and parse, thus mitigating the file size. :smile:

Of course this is not a complete IR, but a start.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![GCC][gcc]][https://gcc.gnu.org/]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

* Bazel
  ```sh
  # For Debian Based Distrobutions
  sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3D5919B448457EE0
	curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel-release.pub
	sudo mv bazel-release.pub /etc/apt/trusted.gpg.d/
	echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
	sudo apt install bazel
  ```

### Installation

1. Clone this repository to your local PC
2. Run `make installbazel` to install Bazel, the used buildtool.
3. Then run `make build` to build the project.
4. Then run `sudo mv qil /bin/` (Might require passcode).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE -->
## Usage

To use this IL (IR), run the command: `qil <input>.qil -o <output>.asm` to generate the fitting Assembly.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Finish the Lexer (Yet)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "verbesserung".
Don't forget to give the project a star! Thanks again!

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

See `LICENSE` for more information.
