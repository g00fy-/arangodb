////////////////////////////////////////////////////////////////////////////////
/// @brief query cursors
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2010-2012 triagens GmbH, Cologne, Germany
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
/// @author Jan Steemann
/// @author Copyright 2012, triagens GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_DURHAM_VOC_BASE_QUERY_CURSOR_H
#define TRIAGENS_DURHAM_VOC_BASE_QUERY_CURSOR_H 1

#include <BasicsC/vector.h>
#include <BasicsC/logging.h>

#include "VocBase/vocbase.h"
#include "VocBase/shadow-data.h"
#include "VocBase/query-base.h"
#include "VocBase/query-result.h"

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                      public types
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup VocBase
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief result cursor
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_query_cursor_s {
  TRI_vocbase_t* _vocbase;
  char* _functionCode;
  bool _isConstant;
  bool _hasCount;
  uint32_t _batchSize;
  TRI_vector_pointer_t _containers;
  TRI_mutex_t _lock;
  bool _deleted;

  TRI_vector_pointer_t* _locks;

  TRI_rc_result_t _result;
  TRI_select_size_t _length;
  TRI_select_size_t _currentRow;

  void (*free) (struct TRI_query_cursor_s*);
  TRI_rc_result_t* (*next)(struct TRI_query_cursor_s* const);
  bool (*hasNext)(const struct TRI_query_cursor_s* const);
  bool (*hasCount)(const struct TRI_query_cursor_s* const);
  uint32_t (*getBatchSize)(const struct TRI_query_cursor_s* const);
}
TRI_query_cursor_t;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup VocBase
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief frees a cursor 
////////////////////////////////////////////////////////////////////////////////

void TRI_FreeQueryCursor (TRI_query_cursor_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create a cursor
////////////////////////////////////////////////////////////////////////////////

TRI_query_cursor_t* TRI_CreateQueryCursor (TRI_query_instance_t* const, 
                                           const TRI_select_result_t* const,
                                           const bool,
                                           const uint32_t);

////////////////////////////////////////////////////////////////////////////////
/// @brief exclusively lock a query cursor
////////////////////////////////////////////////////////////////////////////////

void TRI_LockQueryCursor (TRI_query_cursor_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief unlock a query cursor
////////////////////////////////////////////////////////////////////////////////

void TRI_UnlockQueryCursor (TRI_query_cursor_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief Free a cursor based on its data pointer
////////////////////////////////////////////////////////////////////////////////

void TRI_FreeShadowQueryCursor (void*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create shadow data store for cursors 
////////////////////////////////////////////////////////////////////////////////

TRI_shadow_store_t* TRI_CreateShadowsQueryCursor (void);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End: