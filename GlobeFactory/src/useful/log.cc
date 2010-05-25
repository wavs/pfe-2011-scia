#include "log.hh"
#include <fstream>
#include <time.h>
#include <assert.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Log::Log()
  : MVerboseLevel(LogVerbose::VERBOSE_NONE),
    MOut(NULL)
{
  this->print[Log::RESUME] = &Log::PrintResume;
  this->print[Log::WARNING] = &Log::PrintWarning;
  this->print[Log::ERROR] = &Log::PrintError;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Log::~Log()
{
  CloseOutput();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Log::SetOutput(const std::string& parOutput)
{
  CloseOutput();

  if (parOutput == "stdout")
    MOut = &std::cout;
  else if (parOutput == "stderr")
    MOut = &std::cerr;
  else
    MOut = new std::ofstream(parOutput.c_str(), std::ios_base::out | std::ios_base::trunc);

  PrintBegin(parOutput);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Log::SetOutput(std::ostream& parOutput)
{
  CloseOutput();
  MOut = &parOutput;
  PrintBegin("an unknown stream");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Log::PrintBegin(const std::string& parOutpurStr) const
{
  long date;
  time(&date);
  *MOut << "=============================================" << std::endl;
  *MOut << "=============================================" << std::endl;
  *MOut << "===== OPEN LOG in " << parOutpurStr << std::endl;
  *MOut << "===== ON " << ctime(&date);
  *MOut << "=============================================" << std::endl;
  *MOut << "=============================================" << std::endl;
  *MOut << std::endl << std::endl;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Log::CloseOutput()
{
  if (MOut == NULL)
    return;

  long date;
  time(&date);
  *MOut << std::endl << std::endl;
  *MOut << "=============================================" << std::endl;
  *MOut << "=============================================" << std::endl;
  *MOut << "===== CLOSE LOG" << std::endl;
  *MOut << "===== ON " << ctime(&date);
  *MOut << "=============================================" << std::endl;
  *MOut << "=============================================" << std::endl;

  std::ofstream* file = dynamic_cast<std::ofstream*> (MOut);
  if (file != NULL)
  {
    file->close();
    delete file;
  }

  MOut = 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Log::Send(const std::string& parCat, const std::string& parMsg, MsgType parType)
{
  if (MOut == NULL)
    return;

  if ((parType & MVerboseLevel) != 0)
  {
    (this->*print[parType])();
    *this->MOut << parCat << "\t: " << parMsg << std::endl;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
