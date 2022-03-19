# Build
## update translations
1. call the make target update_translations
2. update the ts file(s) with the Qt linguist tool
3. call make to build the qm file(s)
# Run
## Run with debug output
QT_LOGGING_RULES="*.debug=false;main.debug=true" QtDart
