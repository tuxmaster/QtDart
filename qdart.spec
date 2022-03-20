# Enable git master build
%bcond_with git

Name:		qdart
Version:	1.0.0
Release:	1%{?dist}
License:	GPLv3+
Url:		https://github.com/tuxmaster/QtDart
Summary:	Counts the points of an dart game
Summary(de):	Eine Punktzählung für's Dartspielen
%if %{with git}
Source0:	QtDart-master.tar.xz
%else
Source0:	%{name}-%{version}.tar.xz
%endif
BuildRequires:	cmake(Qt6Core) cmake(Qt6Gui) cmake(Qt6LinguistTools) cmake(Qt6Widgets) 
Recommends:	qt6-qttranslation

%description
An very simple tool to analysis your dart game play.

%description -l de
Eine kleine einfache Auswertung der Würfe beim Dart.

%prep
%if %{with git}
%autosetup -n QtDart-master
%else
%autosetup
%endif

%build
%cmake
%cmake_build

%install
%cmake_install
%find_lang QtDart --with-qt

%files -f QtDart.lang
%{_bindir}/QtDart

%check
%ctest

%changelog
* <time stamp> <packager> <<email address>> - <version>-<release>
- Start
