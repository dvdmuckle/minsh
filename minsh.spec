%define name minsh
%define build_timestamp %{lua: print(os.date("%Y%m%d"))}
Name: %{name}		
Version: 1.0	
Release: %{build_timestamp}
Summary: A very simple shell	
Source0: https://github.com/dvdmuckle/minsh/archive/master.tar.gz#/%{name}-%{version}-%{release}.tar.gz
License: GPLv3
BuildRoot: %{_tmppath/%{name}-buildroot}
BuildRequires: gcc	

%description

A very simple shell that supports running commands and output redirection.

%prep
%autosetup -n %{name}-master


%build
make 


%install
mkdir %{buildroot}/usr/bin -p
cp minsh %{buildroot}/usr/bin/



%files
/usr/bin/minsh
%doc



%changelog

