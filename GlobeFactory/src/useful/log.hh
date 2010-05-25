////////////////////////////////////////////////////////////////////////////////
// Filename  : log.hh
// Authors   : Creteur Clement
// Last edit : 02/10/09 - 19h34
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_LOG_HH
#define USEFUL_LOG_HH

#include <string>
#include <map>
#include <assert.h>
#include <sstream>
#include "singleton.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace LogVerbose
{
  const unsigned VERBOSE_NONE     = 0x0000;
  const unsigned VERBOSE_RESUME   = 0x0001;
  const unsigned VERBOSE_WARNING  = 0x0010;
  const unsigned VERBOSE_ERROR    = 0x0100;
  const unsigned VERBOSE_ALL      = 0x0111;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Log : public Singleton<Log>
{
  friend class Singleton<Log>;
  public:

    static const unsigned VERBOSE_NONE     = 0x0000;
    static const unsigned VERBOSE_RESUME   = 0x0001;
    static const unsigned VERBOSE_WARNING  = 0x0010;
    static const unsigned VERBOSE_ERROR    = 0x0100;
    static const unsigned VERBOSE_ALL      = 0x0111;

    enum MsgType
    {
      RESUME       = 0x0001,
      WARNING      = 0x0010,
      ERROR        = 0x0100
    };

    inline void SetVerboseLevel(unsigned parLevel) {MVerboseLevel = parLevel;}
    void SetOutput(const std::string& parOutput);
    void SetOutput(std::ostream& parOutput);
    void Send(const std::string&, const std::string&, MsgType);

  private:
    Log();
    Log(const Log&) {}
    ~Log();

    void PrintBegin(const std::string&) const;

    inline void PrintWarning() {*MOut << "[WARNING] ";}
    inline void PrintResume()  {*MOut << "[RESUME]  ";}
    inline void PrintError()   {*MOut << "[ERROR]   ";}

    void CloseOutput();

    unsigned MVerboseLevel;
    std::map<MsgType, void (Log::*)()> print;
    std::ostream* MOut;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#define LOG_RESUME(LOC, DESC)                                                  \
          Log::get()->Send(LOC, DESC, Log::RESUME)
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#define LOG_WARNING(LOC, DESC)                                                 \
          Log::get()->Send(LOC, DESC, Log::WARNING)

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#define LOG_ERROR(LOC, DESC)                                                   \
          Log::get()->Send(LOC, DESC, Log::ERROR)

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#ifdef DEBUG

  #define LOG_ASSERT(TEST)                                                     \
            if ((TEST) == 0)                                                   \
            {                                                                  \
              Log::get()->Send("File", __FILE__, Log::ERROR);                  \
              std::stringstream s; s << __LINE__;                              \
              Log::get()->Send("Line", s.str(), Log::ERROR);                   \
              Log::get()->Send("Assert", "No Description", Log::ERROR);        \
              Log::kill();                                                     \
              assert(TEST);                                                    \
            }

  #define LOG_ASSERT_WITH_DESC(TEST, DESC)                                     \
            if ((TEST) == 0)                                                   \
            {                                                                  \
              Log::get()->Send("File", __FILE__, Log::ERROR);                  \
              std::stringstream s; s << __LINE__;                              \
              Log::get()->Send("Line", s.str(), Log::ERROR);                   \
              Log::get()->Send("Assert", DESC, Log::ERROR);                    \
              Log::kill();                                                     \
              assert(TEST);                                                    \
            }

  #define LOG_RESUME_DEBUG(LOC, DESC)                                          \
            Log::get()->Send(LOC, DESC, Log::RESUME)

#else

  #define LOG_ASSERT(TEST)

  #define LOG_ASSERT_WITH_DESC(TEST, DESC)

  #define LOG_RESUME_DEBUG(LOC, DESC)

#endif

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
