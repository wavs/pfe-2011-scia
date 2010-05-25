#include "menu.hh"

/* FIXME (TEST) */
#include "../gfx/vertex_writer.hh"
#include "../gfx/vertex.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/renderer_2D.hh"
#include "../gfx/texture_mng.hh"
#include "../gfx/render_string.hh"
#include "../ui/interface_mng.hh"
#include "../ui/ui_button.hh"
#include "../ui/ui_window.hh"
#include "../ui/ui_check_box.hh"
#include "../ui/ui_combo_box.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/* FIXME (TEST) */
unsigned material_id     = 0;
RenderString* render_str = NULL;
unsigned MInterface      = 0;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Menu::Menu()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Menu::~Menu()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Menu::Update()
{
  VertexWriter<Vertex::TV3F>& vertexWriter = GfxEngine::get()->GetPreRender2D()->GetVertexWriter<Vertex::TV3F>(material_id, 3, 1);

  Vertex::TV3F* vertex = NULL;
  vertex = &vertexWriter.GetVertex(0);
  vertex->position = Vector3(160.0f ,120.0f, 0.0f);

  vertex = &vertexWriter.GetVertex(1);
  vertex->position = Vector3(320.0f, 360.0f, 0.0f);

  vertex = &vertexWriter.GetVertex(2);
  vertex->position = Vector3(480.0f, 120.0f, 0.0f);

  vertexWriter.AddTriangle(0, 1, 2);
  vertexWriter.Finish();

  render_str->SetAligments(AligmentEnum::RIGHT, AligmentEnum::TOP);
  render_str->Draw(Vector2f(0.0f, 0.0f));
  render_str->SetAligments(AligmentEnum::RIGHT, AligmentEnum::BOTTOM);
  render_str->Draw(Vector2f(0.0f, 600.0f));
  render_str->SetAligments(AligmentEnum::LEFT, AligmentEnum::TOP);
  render_str->Draw(Vector2f(800.0f, 0.0f));

  Vector2f a(0.0f, 0.0f);
  Vector2f b(400.0f, 300.0f);
  Vector2f c(800.0f, 0.0f);
  Vector2f min(50.0f, 50.0f);
  Vector2f max(300.0f, 250.0f);

  GfxEngine::get()->GetPreRender2D()->DrawLine(a, b, BaseColor::GOLD);
  GfxEngine::get()->GetPreRender2D()->DrawLine(b, c, BaseColor::ORANGERED);

  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(400, 400), Vector2f(440, 440)), BaseColor::YELLOWGREEN);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(405, 405), Vector2f(445, 445)), BaseColor::FIREBRICK);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(410, 410), Vector2f(450, 450)), BaseColor::GOLDENROD);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(415, 415), Vector2f(455, 455)), BaseColor::VIOLET);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(420, 420), Vector2f(460, 460)), BaseColor::VIOLETRED);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(425, 425), Vector2f(465, 465)), BaseColor::IVORY);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(430, 430), Vector2f(470, 470)), BaseColor::TAN);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(435, 435), Vector2f(475, 475)), BaseColor::THISTLE);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(440, 440), Vector2f(480, 480)), BaseColor::TOMATO);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(445, 445), Vector2f(485, 485)), material_id);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(450, 450), Vector2f(490, 490)), BaseColor::PAPAYAWHIP);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(455, 455), Vector2f(495, 495)), BaseColor::PERU);
  GfxEngine::get()->GetPostRender2D()->DrawQuad(BB2f(Vector2f(460, 460), Vector2f(500, 500)), BaseColor::TURQUOISE);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Menu::OnLaunchMenu()
{
  material_id = MaterialMng::get()->LoadMaterial("anim.txt");

  render_str = new RenderString("arial.ttf", 32);
  render_str->Set("Test String TEST");
  render_str->SetColor(BaseColor::BROWN);

  MInterface = InterfaceMng::get()->LoadFromXML("menu.xml");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Menu::OnLeaveMenu()
{
  MaterialMng::get()->UnloadMaterial(material_id);
  delete render_str;
  InterfaceMng::get()->DeleteInterface(MInterface);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
