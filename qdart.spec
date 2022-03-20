Name:		qdart
Version:	1.0.0
Release:	1%{?dist}
License:	gpv3+
Url:		https://github.com/tuxmaster/QtDart
Summary:	Counts the points of an dart game
Summary(de):	Eine Punktzählung für's Dartspielen
Source0:	%{name}-%{version}.tar.xz
BuildRequires:	cmake(Qt6Core) cmake(Qt6Gui) cmake(Qt6LinguistTools) cmake(Qt6Widgets) 
Recommends:	qt6-qttranslation

%description
An very simple tool to analysis your dart game play.

%description -l de
Eine kleine einfache Auswertung der Würfe beim Dart.

%prep

%build

%install
