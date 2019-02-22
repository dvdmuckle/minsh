%define name minsh
%define build_timestamp %{lua: print(os.date("%Y%m%d"))}
%define version 1.9.1
Name: %{name}		
Version: %{version}	
Release: %{build_timestamp}%{?dist}
Summary: A very simple shell	
Source0: https://github.com/dvdmuckle/minsh/archive/master.tar.gz#/%{name}-%{version}-%{release}.tar.gz
License: GPLv3
Packager: David Muckle <dvdmuckle@dvdmuckle.xyz>
BuildRequires: gcc make

%description

A very simple shell that supports running commands and output redirection.
%global debug_package %{nil}
%prep
%autosetup -n %{name}-master


%build
make 


%install
mkdir %{buildroot}%{_bindir} -p
install -s minsh.o  %{buildroot}%{_bindir}/minsh

%clean
rm -rf %{buildroot}

%files
%{_bindir}/minsh
%doc



%changelog

