# Build
## build the app
1. cmake -B <build dir>
2. cmake --build <build dir> --parallel <cpu core numbers>
## update translations
1. cmake --build <build dir> --target update_translations
2. update the ts file(s) with the Qt linguist tool
3. cmake --build <build dir>
# Run
## Run with debug output
QT_LOGGING_RULES="*.debug=false;main.debug=true" QtDart
