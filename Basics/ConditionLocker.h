////////////////////////////////////////////////////////////////////////////////
/// @brief Condition Locker
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2012 triagens GmbH, Cologne, Germany
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
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Achim Brandt
/// @author Copyright 2008-2012, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_BASICS_CONDITION_LOCKER_H
#define TRIAGENS_BASICS_CONDITION_LOCKER_H 1

#include "Basics/Common.h"

#include "Basics/ConditionVariable.h"

// -----------------------------------------------------------------------------
// --SECTION--                                                     public macros
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Threading
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief construct locker with file and line information
////////////////////////////////////////////////////////////////////////////////

#define CONDITION_LOCKER(a, b) \
  triagens::basics::ConditionLocker a(&b, __FILE__, __LINE__)

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                  class ReadLocker
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Threading
/// @{
////////////////////////////////////////////////////////////////////////////////

namespace triagens {
  namespace basics {

////////////////////////////////////////////////////////////////////////////////
/// @brief condition locker
///
/// A ConditionLocker locks a condition when constructed and releases the lock
/// when destroyed. It is possible the wait for an event in which case the lock
/// is released or to broadcast an event.
////////////////////////////////////////////////////////////////////////////////

    class  ConditionLocker {
        ConditionLocker (ConditionLocker const&);
        ConditionLocker& operator= (ConditionLocker const&);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                      constructors and destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Threading
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief locks the condition variable
///
/// The constructors locks the condition variable, the destructors unlocks
/// the condition variable
////////////////////////////////////////////////////////////////////////////////

        explicit
        ConditionLocker (ConditionVariable* conditionVariable);

////////////////////////////////////////////////////////////////////////////////
/// @brief locks the condition variable
///
/// The constructors locks the condition variable, the destructors unlocks
/// the condition variable
////////////////////////////////////////////////////////////////////////////////

        ConditionLocker (ConditionVariable* conditionVariable, char const* file, int line);

////////////////////////////////////////////////////////////////////////////////
/// @brief unlocks the condition variable
////////////////////////////////////////////////////////////////////////////////

        ~ConditionLocker ();

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                    public methods
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Threading
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief waits for an event to occur
////////////////////////////////////////////////////////////////////////////////

        void wait ();

////////////////////////////////////////////////////////////////////////////////
/// @brief broadcasts an event
////////////////////////////////////////////////////////////////////////////////

        void broadcast ();

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                 private variables
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Threading
/// @{
////////////////////////////////////////////////////////////////////////////////

      private:

////////////////////////////////////////////////////////////////////////////////
/// @brief the condition
////////////////////////////////////////////////////////////////////////////////

        ConditionVariable* _conditionVariable;

////////////////////////////////////////////////////////////////////////////////
/// @brief file
////////////////////////////////////////////////////////////////////////////////

        char const* _file;

////////////////////////////////////////////////////////////////////////////////
/// @brief line number
////////////////////////////////////////////////////////////////////////////////

        int _line;
    };
  }
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End: