import gf

print "[DEBUT]"

ge = gf.PythonGF();
ge.Initialize();

mat = ge.LoadMaterial("fun.txt");

txt = ge.CreateText2D("TEST", "arial.ttf");
ge.SetText2DColor(txt, 0.0, 1.0, 0.0)
ge.SetText2DSize(txt, 64)

run = True
while run:
    ge.DrawLine(0,0,800,600,1.0,0.0,0.0);
    ge.DrawQuad(100,75,600,450,mat);
    ge.DrawText2D(txt, 350, 525);
    run = ge.Frame();

ge.DeleteText2D(txt);
ge.UnloadMaterial(mat);

print "[FIN]"
