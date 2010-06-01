import gf

print "[DEBUT]"

ge = gf.PythonGF();
ge.Initialize();

run = True
while run:
    run = ge.Frame();

print "[FIN]"
