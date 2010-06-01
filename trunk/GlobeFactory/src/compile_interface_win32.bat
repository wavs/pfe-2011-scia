swig -python -c++ gf.i
g++ -LG:\python26\libs --shared *.cc *_wrap.cxx game/*.cc game/cinematic/*.cc ui/*.cc ui/ui_loader/*.cc gfx/*.cc gfx/material_def/*.cc useful/*.cc useful/tinyxml/*.cpp -lpython26 -lSDLmain -lSDL -lglu32 -lopengl32 -lSDL_ttf -lSDL_image -lboost_thread -o _gf.pyd
pause
