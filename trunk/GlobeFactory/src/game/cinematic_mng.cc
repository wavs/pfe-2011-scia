#include "cinematic_mng.hh"
#include "cinematic/intro_cinematic.hh"
#include "cinematic/file_cinematic.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

CinematicMng::CinematicMng()
  : MCurCinematic(NULL),
    MArg("")
{
  MCinematics["intro"] = new IntroCinematic();
  MCinematics["@"]     = new FileCinematic();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

CinematicMng::~CinematicMng()
{
  foreach(it, MCinematics)
    delete it->second;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CinematicMng::Load(const std::string parArg)
{
  LOG_ASSERT(!parArg.empty());
  MArg = parArg;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CinematicMng::Update()
{
  if (MCurCinematic != NULL)
    MCurCinematic->Update();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CinematicMng::OnLaunchCinematic()
{
  LOG_ASSERT(!MArg.empty());

  if (MArg[0] == '@')
  {
    LOG_ASSERT(MCinematics.count("@") != 0);
    MCurCinematic = MCinematics["@"];
    MCurCinematic->Start(MArg.substr(1));
  }
  else
  {
    LOG_ASSERT(MCinematics.count(MArg) != 0);
    MCurCinematic = MCinematics[MArg];
    MCurCinematic->Start();
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CinematicMng::OnLeaveCinematic()
{
  LOG_ASSERT(MCurCinematic != NULL);
  MArg = "";
  LOG_RESUME("CinematicMng", "Leave current cinematic");
  MCurCinematic->Finish();
  MCurCinematic = NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
