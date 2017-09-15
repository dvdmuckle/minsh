# minsh
[![Build Status](https://travis-ci.org/dvdmuckle/minsh.svg?branch=master)](https://travis-ci.org/dvdmuckle/minsh)[![rpmbuild](https://copr.fedorainfracloud.org/coprs/dvdmuckle/minsh/package/minsh/status_image/last_build.png)](https://copr.fedorainfracloud.org/coprs/dvdmuckle/minsh/package/minsh/)

A very simple shell.

### Install

#### Fedora
A Copr repo for Fedora 25, 26, 27, and rawhide is supplied.

```
sudo dnf copr enable dvdmuckle/minsh
sudo dnf install minsh
```

#### Ubuntu
Packages for Ubuntu Trusty and Xenial are available.

```
curl -s https://packagecloud.io/install/repositories/dvdmuckle/minsh/script.deb.sh | sudo bash
sudo apt-get install minsh
```
### Compile

`make && sudo make install`

Will install to your /usr/bin folder.

Alternatively, `make && make test-install` will install to your current directory.

### Use

Start with `minsh`. Use `minsh --help` for more information. Use `minsh -v` to start in verbose mode.
