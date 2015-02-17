////////////////////////////////////////////////////////////////////////////////
/// @brief program options description
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2014 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Copyright 2014, ArangoDB GmbH, Cologne, Germany
/// @author Copyright 2010-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_BASICS_PROGRAM_OPTIONS_DESCRIPTION_H
#define ARANGODB_BASICS_PROGRAM_OPTIONS_DESCRIPTION_H 1

#include "Basics/Common.h"
#include <functional>

namespace triagens {
  namespace basics {

// -----------------------------------------------------------------------------
// --SECTION--                                   class ProgramOptionsDescription
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @brief ProgramOptionsDescription
////////////////////////////////////////////////////////////////////////////////

    class ProgramOptionsDescription {
      friend class ProgramOptions;

// -----------------------------------------------------------------------------
// --SECTION--                                      constructors and destructors
// -----------------------------------------------------------------------------

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief constructor
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription ();

////////////////////////////////////////////////////////////////////////////////
/// @brief constructor
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription (const std::string& name);

////////////////////////////////////////////////////////////////////////////////
/// @brief copy constructor
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription (const ProgramOptionsDescription&);

////////////////////////////////////////////////////////////////////////////////
/// @brief assignment constructor
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator= (const ProgramOptionsDescription&);

// -----------------------------------------------------------------------------
// --SECTION--                                                    public methods
// -----------------------------------------------------------------------------

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief changes the name
////////////////////////////////////////////////////////////////////////////////

        void setName (const std::string& name);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a new visible or hidden section
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (ProgramOptionsDescription&, bool hidden = false);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a new flag
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a string argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::string* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a string vector argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::vector<std::string>* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an int32_t argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, int32_t* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an int32_t vector argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::vector<int32_t>* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an int64_t argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, int64_t* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an int64_t vector argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::vector<int64_t>* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an uint32_t argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, uint32_t* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an uint32_t vector argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::vector<uint32_t>* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an uint64_t argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, uint64_t* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds an uint64_t vector argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::vector<uint64_t>* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a double argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, double* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a double vector argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, std::vector<double>* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a boolean argument
////////////////////////////////////////////////////////////////////////////////

        ProgramOptionsDescription& operator() (const std::string& name, bool* value, const std::string& text);

////////////////////////////////////////////////////////////////////////////////
/// @brief adds a time_t argument
////////////////////////////////////////////////////////////////////////////////

#if __WORDSIZE == 32
        ProgramOptionsDescription& operator() (const std::string& name, time_t* value, const std::string& text);
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief adds positional arguments
////////////////////////////////////////////////////////////////////////////////

        void arguments (std::vector<std::string>*);

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the usage message
////////////////////////////////////////////////////////////////////////////////

        std::string usage () const;

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the usage message for given sections
////////////////////////////////////////////////////////////////////////////////

        std::string usage (std::set<std::string> help) const;

////////////////////////////////////////////////////////////////////////////////
/// @brief returns a list of help options
////////////////////////////////////////////////////////////////////////////////

        std::set<std::string> helpOptions () const;

// -----------------------------------------------------------------------------
// --SECTION--                                                      public types
// -----------------------------------------------------------------------------

      private:

////////////////////////////////////////////////////////////////////////////////
/// @brief option types
////////////////////////////////////////////////////////////////////////////////

        enum option_type_e {
          OPTION_TYPE_FLAG,
          OPTION_TYPE_STRING,
          OPTION_TYPE_VECTOR_STRING,
          OPTION_TYPE_INT32,
          OPTION_TYPE_VECTOR_INT64,
          OPTION_TYPE_INT64,
          OPTION_TYPE_VECTOR_INT32,
          OPTION_TYPE_UINT32,
          OPTION_TYPE_VECTOR_UINT32,
          OPTION_TYPE_UINT64,
          OPTION_TYPE_VECTOR_UINT64,
          OPTION_TYPE_DOUBLE,
          OPTION_TYPE_VECTOR_DOUBLE,
          OPTION_TYPE_BOOL,
          OPTION_TYPE_TIME
        };

// -----------------------------------------------------------------------------
// --SECTION--                                                   private methods
// -----------------------------------------------------------------------------

      private:

////////////////////////////////////////////////////////////////////////////////
/// @brief computes all names
////////////////////////////////////////////////////////////////////////////////

        void fillAllNames (const std::set<std::string>& help,
                           std::map<std::string, std::string>& names) const;

////////////////////////////////////////////////////////////////////////////////
/// @brief returns the usage message for given sections
////////////////////////////////////////////////////////////////////////////////

        std::string usageString (const std::set<std::string>& help,
                                 const std::map<std::string, std::string>& names,
                                 size_t oWidth) const;

////////////////////////////////////////////////////////////////////////////////
/// @brief constructs the usage string
////////////////////////////////////////////////////////////////////////////////

        std::string usageString (const std::map<std::string, std::string>& names,
                                 size_t oWidth) const;

////////////////////////////////////////////////////////////////////////////////
/// @brief checks if the name is an option, defines short/long mapping
////////////////////////////////////////////////////////////////////////////////

        std::string check (const std::string& name);

////////////////////////////////////////////////////////////////////////////////
/// @brief checks if the name is an option, defines short/long mapping
////////////////////////////////////////////////////////////////////////////////

        std::string check (const std::string& name, void* value);

// -----------------------------------------------------------------------------
// --SECTION--                                                 private variables
// -----------------------------------------------------------------------------

      private:

////////////////////////////////////////////////////////////////////////////////
/// @brief name of the section
////////////////////////////////////////////////////////////////////////////////

        std::string _name;

////////////////////////////////////////////////////////////////////////////////
/// @brief help options
////////////////////////////////////////////////////////////////////////////////

        std::set<std::string> _helpOptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief sub-descriptions
////////////////////////////////////////////////////////////////////////////////

        std::vector<ProgramOptionsDescription> _subDescriptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief hidden sub-descriptions
////////////////////////////////////////////////////////////////////////////////

        std::vector<ProgramOptionsDescription> _hiddenSubDescriptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief defined option names
////////////////////////////////////////////////////////////////////////////////

        std::vector<std::string> _optionNames;

////////////////////////////////////////////////////////////////////////////////
/// @brief type of an option
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, option_type_e> _optionTypes;

////////////////////////////////////////////////////////////////////////////////
/// @brief short name of an option
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::string> _long2short;

////////////////////////////////////////////////////////////////////////////////
/// @brief help text of an option
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::string> _helpTexts;

////////////////////////////////////////////////////////////////////////////////
/// @brief default of an option
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::string> _defaultTexts;

////////////////////////////////////////////////////////////////////////////////
/// @brief current text of an option
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::function<std::string (void*)>> _currentTexts;

////////////////////////////////////////////////////////////////////////////////
/// @brief value of an option
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, void*> _values;

////////////////////////////////////////////////////////////////////////////////
/// @brief all string options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::string*> _stringOptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief all vector string options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::vector<std::string>*> _vectorStringOptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief all int32 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, int32_t*> _int32Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all vector int32 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::vector<int32_t>*> _vectorInt32Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all int64 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, int64_t*> _int64Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all vector int64 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::vector<int64_t>*> _vectorInt64Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all uint32 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, uint32_t*> _uint32Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all vector uint32 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::vector<uint32_t>*> _vectorUInt32Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all uint64 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, uint64_t*> _uint64Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all vector uint64 options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::vector<uint64_t>* > _vectorUInt64Options;

////////////////////////////////////////////////////////////////////////////////
/// @brief all double options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, double*> _doubleOptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief all vector double options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, std::vector<double>*> _vectorDoubleOptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief all boolean options
////////////////////////////////////////////////////////////////////////////////

        std::map<std::string, bool*> _boolOptions;

////////////////////////////////////////////////////////////////////////////////
/// @brief all time options
////////////////////////////////////////////////////////////////////////////////

#if __WORDSIZE == 32
        std::map<std::string, time_t*> _timeOptions;
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief all positional arguments
////////////////////////////////////////////////////////////////////////////////

        std::vector<std::string>* _positionals;
    };
  }
}

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @page\\|// --SECTION--\\|/// @\\}"
// End: