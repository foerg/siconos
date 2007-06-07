Summary: Documentation for Siconos software
Version: 2.0.1
Name: siconos-docs
Release: 1
License: GNU LGPL
Group: Application/Math
URL: http://gforge.inria.fr/projects/siconos
Source0: siconos-docs-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
BuildPreReq: autoconf, automake, doxygen, tetex-latex 
Requires: siconos-numerics, siconos-kernel

%description 
This package makes the documentation for Siconos software
available under %{_datadir}/doc/siconos-%{version} 

%define component Docs
%define namev %{name}-%{version}
%define gdocs GeneratedDocs
%define docs %{_datadir}/doc/siconos-%{version}

%prep
%setup -q -c
mkdir -p %{gdocs}/Tags

%build
pushd %{namev}
%{configure}
%{__make}

%install
pushd %{namev}
rm -rf %{buildroot}
mkdir -p %{buildroot}%{docs}/html
mkdir -p %{buildroot}%{docs}/pdf
mkdir -p %{buildroot}%{docs}/%{component}
%{__install} AUTHORS COPYING ChangeLog NEWS README %{buildroot}%{docs}/%{component}
pdfs=`find . -name \*.pdf`; [ x"$pdfs" = x ] || cp $pdfs %{buildroot}%{docs}/pdf
cp css/logo_bipop.png %{buildroot}%{docs}/html
popd
pushd %{gdocs} 
rm -rf `find . -name latex -type d`
pdfs=`find . -name \*.pdf`; [ x"$pdfs" = x ] || cp $pdfs %{buildroot}%{docs}/pdf
tar cvf - . | (cd %{buildroot}%{docs}/html ; tar xvf -)

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%doc %{docs}

%changelog
* Thu May 31 2007 Maurice Bremond <Maurice.Bremond@inria.fr> - 2.0.1-1
- Initial rpm



