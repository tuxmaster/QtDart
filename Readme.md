# Build
## RPM build
### from git master
1. download the zip master
2. unzip -o QtDart-master.zip&&tar -cJf QtDart-master.tar.xz QtDart-master&&rpmbuild -ts QtDart-master.tar.xz --with git
3. mock -r \<chroot\> \<path to the SRPM file\> --with git
## Generic build
### Hint for win64 cross compile on Fedora
1. dnf install mingw64-gcc-c++
2. add the option -DCMAKE_TOOLCHAIN_FILE=/usr/share/mingw/toolchain-mingw64.cmake to the first cmake call
The Qt6 part are only working on Fedora >35
### build the app
1. cmake -B \<build dir\>
2. cmake --build \<build dir\> --parallel \<cpu core numbers\>
3. cmake --install \<build dir\>
### update translations
1. cmake --build \<build dir\> --target update_translations
2. update the ts file(s) with the Qt linguist tool
3. cmake --build \<build dir\>
# Run
## Run with debug output
QT_LOGGING_RULES="*.debug=false;qdart.*.debug=true" QtDart
