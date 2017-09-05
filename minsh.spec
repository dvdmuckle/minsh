%define name minsh
%define build_timestamp %{lua: print(os.date("%Y%m%d"))}
%define version 1.0
Name: %{name}		
Version: %{version}	
Release: %{build_timestamp}
Summary: A very simple shell	
Source0: https://github.com/dvdmuckle/minsh/archive/master.tar.gz#/%{name}-master.tar.gz
License: GPLv3
BuildRequires: gcc	

%description

A very simple shell that supports running commands and output redirection.

%prep
%autosetup -n %{name}-master.tar.gz


%build
make 


%install
mkdir %{buildroot}${_bindir} -p
install -s minsh.o  %{buildroot}/usr/bin/

%clean
rm -rf %{buildroot}

%files
${_bindir}/minsh
%doc



%changelog

