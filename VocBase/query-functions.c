////////////////////////////////////////////////////////////////////////////////
/// @brief In-query functions
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

#include "VocBase/query-functions.h"

// -----------------------------------------------------------------------------
// --SECTION--                                                 private functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup VocBase
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Hash function used to hash function struct
////////////////////////////////////////////////////////////////////////////////

static uint64_t HashFunction (TRI_associative_pointer_t* array, 
                              void const* element) {
  TRI_query_function_t* function = (TRI_query_function_t*) element;

  return TRI_FnvHashString(function->_externalName);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Comparison function used to determine function name equality
////////////////////////////////////////////////////////////////////////////////

static bool EqualName (TRI_associative_pointer_t* array, 
                       void const* key, 
                       void const* element) {
  TRI_query_function_t* function = (TRI_query_function_t*) element;

  return TRI_EqualString(key, function->_externalName);
}

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
/// @brief initialise the array with the function declarations 
////////////////////////////////////////////////////////////////////////////////

TRI_associative_pointer_t* TRI_InitialiseQueryFunctions (void) {
  TRI_associative_pointer_t* functions = 
    (TRI_associative_pointer_t*) TRI_Allocate(sizeof(TRI_associative_pointer_t)); 

  if (!functions) {
    return NULL;
  }

  TRI_InitAssociativePointer(functions, 
                             TRI_HashStringKeyAssociativePointer, 
                             HashFunction, 
                             EqualName, 
                             NULL); 

  // cast functions
  TRI_RegisterQueryFunction(functions, "toNumber", "AQL_CAST_NUMBER", 1, 1);
  TRI_RegisterQueryFunction(functions, "toString", "AQL_CAST_STRING", 1, 1);
  TRI_RegisterQueryFunction(functions, "toBool", "AQL_CAST_BOOL", 1, 1);
  TRI_RegisterQueryFunction(functions, "toNull", "AQL_CAST_NULL", 1, 1);
  TRI_RegisterQueryFunction(functions, "toUndefined", "AQL_CAST_UNDEFINED", 1, 1);
  
  // type check functions
  TRI_RegisterQueryFunction(functions, "isString", "AQL_IS_STRING", 1, 1);
  TRI_RegisterQueryFunction(functions, "isNumber", "AQL_IS_NUMBER", 1, 1);
  TRI_RegisterQueryFunction(functions, "isBool", "AQL_IS_BOOL", 1, 1);
  TRI_RegisterQueryFunction(functions, "isNull", "AQL_IS_NULL", 1, 1);
  TRI_RegisterQueryFunction(functions, "isUndefined", "AQL_IS_UNDEFINED", 1, 1);
  TRI_RegisterQueryFunction(functions, "isArray", "AQL_IS_ARRAY", 1, 1);
  TRI_RegisterQueryFunction(functions, "isObject", "AQL_IS_OBJECT", 1, 1);
  
  // string concat
  TRI_RegisterQueryFunction(functions, "concat", "AQL_STRING_CONCAT", 1, 1024);

  return functions;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief free the array with the function declarations 
////////////////////////////////////////////////////////////////////////////////

void TRI_FreeQueryFunctions (TRI_associative_pointer_t* functions) {
  TRI_query_function_t* function;
  size_t i;

  for (i = 0; i < functions->_nrAlloc; ++i) {
    function = (TRI_query_function_t*) functions->_table[i];
    if (!function) {
      continue;
    }

    TRI_Free(function->_externalName);
    TRI_Free(function->_internalName);
    TRI_Free(function);
  }

  TRI_DestroyAssociativePointer(functions);
  TRI_Free(functions);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief check if a function name is valid
////////////////////////////////////////////////////////////////////////////////

bool TRI_IsValidQueryFunction (TRI_associative_pointer_t* functions,
                               const char* const externalName) {
  if (TRI_LookupByKeyAssociativePointer(functions, externalName)) {
    return true;
  }

  return false;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief get internal function name for an external one
////////////////////////////////////////////////////////////////////////////////

char* TRI_GetInternalNameQueryFunction (TRI_associative_pointer_t* functions,
                                        const char* const externalName) {
  TRI_query_function_t* function = (TRI_query_function_t*) 
    TRI_LookupByKeyAssociativePointer(functions, externalName);

  if (!function) {
    return NULL;
  }

  return function->_internalName;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief register a function name
////////////////////////////////////////////////////////////////////////////////

bool TRI_RegisterQueryFunction (TRI_associative_pointer_t* functions,
                                const char* const externalName, 
                                const char* const internalName, 
                                const int minArgs, 
                                const int maxArgs) {
  TRI_query_function_t* function = 
    (TRI_query_function_t*) TRI_Allocate(sizeof(TRI_query_function_t));

  if (!function) {
    return false;
  }

  function->_externalName = TRI_DuplicateString(externalName);
  if (!function->_externalName) {
    TRI_Free(function);
    return false;
  }

  function->_internalName = TRI_DuplicateString(internalName);
  if (!function->_internalName) {
    TRI_Free(function->_externalName);
    TRI_Free(function);
    return false;
  }
  function->_minArgs = minArgs; 
  function->_maxArgs = maxArgs; 

  if (TRI_InsertKeyAssociativePointer(functions, externalName, function, false)) {
    TRI_Free(function->_externalName);
    TRI_Free(function->_internalName);
    TRI_Free(function);
    return false;
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End:
