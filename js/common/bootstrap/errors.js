////////////////////////////////////////////////////////////////////////////////
/// @brief auto-generated file generated from errors.dat
////////////////////////////////////////////////////////////////////////////////

var internal = require("internal");

ModuleCache["/internal"].exports.errors = {
  "ERROR_NO_ERROR"               : { "code" : 0, "message" : "no error" }, 
  "ERROR_FAILED"                 : { "code" : 1, "message" : "failed" }, 
  "ERROR_SYS_ERROR"              : { "code" : 2, "message" : "system error" }, 
  "ERROR_OUT_OF_MEMORY"          : { "code" : 3, "message" : "out of memory" }, 
  "ERROR_INTERNAL"               : { "code" : 4, "message" : "internal error" }, 
  "ERROR_ILLEGAL_NUMBER"         : { "code" : 5, "message" : "illegal number" }, 
  "ERROR_NUMERIC_OVERFLOW"       : { "code" : 6, "message" : "numeric overflow" }, 
  "ERROR_ILLEGAL_OPTION"         : { "code" : 7, "message" : "illegal option" }, 
  "ERROR_DEAD_PID"               : { "code" : 8, "message" : "dead process identifier" }, 
  "ERROR_NOT_IMPLEMENTED"        : { "code" : 9, "message" : "not implemented" }, 
  "ERROR_BAD_PARAMETER"          : { "code" : 10, "message" : "bad parameter" }, 
  "ERROR_FORBIDDEN"              : { "code" : 11, "message" : "forbidden" }, 
  "ERROR_OUT_OF_MEMORY_MMAP"     : { "code" : 12, "message" : "out of memory in mmap" }, 
  "ERROR_CORRUPTED_CSV"          : { "code" : 13, "message" : "csv is corrupt" }, 
  "ERROR_HTTP_BAD_PARAMETER"     : { "code" : 400, "message" : "bad parameter" }, 
  "ERROR_HTTP_FORBIDDEN"         : { "code" : 403, "message" : "forbidden" }, 
  "ERROR_HTTP_NOT_FOUND"         : { "code" : 404, "message" : "not found" }, 
  "ERROR_HTTP_METHOD_NOT_ALLOWED" : { "code" : 405, "message" : "method not supported" }, 
  "ERROR_HTTP_SERVER_ERROR"      : { "code" : 500, "message" : "internal server error" }, 
  "ERROR_HTTP_CORRUPTED_JSON"    : { "code" : 600, "message" : "invalid JSON object" }, 
  "ERROR_HTTP_SUPERFLUOUS_SUFFICES" : { "code" : 601, "message" : "superfluous URL suffices" }, 
  "ERROR_AVOCADO_ILLEGAL_STATE"  : { "code" : 1000, "message" : "illegal state" }, 
  "ERROR_AVOCADO_SHAPER_FAILED"  : { "code" : 1001, "message" : "illegal shaper" }, 
  "ERROR_AVOCADO_DATAFILE_SEALED" : { "code" : 1002, "message" : "datafile sealed" }, 
  "ERROR_AVOCADO_UNKNOWN_COLLECTION_TYPE" : { "code" : 1003, "message" : "unknown type" }, 
  "ERROR_AVOCADO_READ_ONLY"      : { "code" : 1004, "message" : "ready only" }, 
  "ERROR_AVOCADO_DUPLICATE_IDENTIFIER" : { "code" : 1005, "message" : "duplicate identifier" }, 
  "ERROR_AVOCADO_CORRUPTED_DATAFILE" : { "code" : 1100, "message" : "corrupted datafile" }, 
  "ERROR_AVOCADO_ILLEGAL_PARAMETER_FILE" : { "code" : 1101, "message" : "illegal parameter file" }, 
  "ERROR_AVOCADO_CORRUPTED_COLLECTION" : { "code" : 1102, "message" : "corrupted collection" }, 
  "ERROR_AVOCADO_MMAP_FAILED"    : { "code" : 1103, "message" : "mmap failed" }, 
  "ERROR_AVOCADO_FILESYSTEM_FULL" : { "code" : 1104, "message" : "filesystem full" }, 
  "ERROR_AVOCADO_NO_JOURNAL"     : { "code" : 1105, "message" : "no journal" }, 
  "ERROR_AVOCADO_DATAFILE_ALREADY_EXISTS" : { "code" : 1106, "message" : "cannot create/rename datafile because it already exists" }, 
  "ERROR_AVOCADO_DATABASE_LOCKED" : { "code" : 1107, "message" : "database is locked" }, 
  "ERROR_AVOCADO_COLLECTION_DIRECTORY_ALREADY_EXISTS" : { "code" : 1108, "message" : "cannot create/rename collection because directory already exists" }, 
  "ERROR_AVOCADO_CONFLICT"       : { "code" : 1200, "message" : "conflict" }, 
  "ERROR_AVOCADO_WRONG_VOCBASE_PATH" : { "code" : 1201, "message" : "wrong path for database" }, 
  "ERROR_AVOCADO_DOCUMENT_NOT_FOUND" : { "code" : 1202, "message" : "document not found" }, 
  "ERROR_AVOCADO_COLLECTION_NOT_FOUND" : { "code" : 1203, "message" : "collection not found" }, 
  "ERROR_AVOCADO_COLLECTION_PARAMETER_MISSING" : { "code" : 1204, "message" : "parameter 'collection' not found" }, 
  "ERROR_AVOCADO_DOCUMENT_HANDLE_BAD" : { "code" : 1205, "message" : "illegal document handle" }, 
  "ERROR_AVOCADO_MAXIMAL_SIZE_TOO_SMALL" : { "code" : 1206, "message" : "maixaml size of journal too small" }, 
  "ERROR_AVOCADO_DUPLICATE_NAME" : { "code" : 1207, "message" : "duplicate name" }, 
  "ERROR_AVOCADO_ILLEGAL_NAME"   : { "code" : 1208, "message" : "illegal name" }, 
  "ERROR_AVOCADO_NO_INDEX"       : { "code" : 1209, "message" : "no suitable index known" }, 
  "ERROR_AVOCADO_UNIQUE_CONSTRAINT_VIOLATED" : { "code" : 1210, "message" : "unique constraint violated" }, 
  "ERROR_AVOCADO_GEO_INDEX_VIOLATED" : { "code" : 1211, "message" : "geo index violated" }, 
  "ERROR_AVOCADO_INDEX_NOT_FOUND" : { "code" : 1212, "message" : "index not found" }, 
  "ERROR_AVOCADO_CROSS_COLLECTION_REQUEST" : { "code" : 1213, "message" : "cross collection request not allowed" }, 
  "ERROR_AVOCADO_INDEX_HANDLE_BAD" : { "code" : 1214, "message" : "illegal index handle" }, 
  "ERROR_AVOCADO_DATAFILE_FULL"  : { "code" : 1300, "message" : "datafile full" }, 
  "ERROR_QUERY_KILLED"           : { "code" : 1500, "message" : "query killed" }, 
  "ERROR_QUERY_PARSE"            : { "code" : 1501, "message" : "parse error: %s" }, 
  "ERROR_QUERY_EMPTY"            : { "code" : 1502, "message" : "query is empty" }, 
  "ERROR_QUERY_SPECIFICATION_INVALID" : { "code" : 1503, "message" : "query specification invalid" }, 
  "ERROR_QUERY_NUMBER_OUT_OF_RANGE" : { "code" : 1504, "message" : "number '%s' is out of range" }, 
  "ERROR_QUERY_TOO_MANY_JOINS"   : { "code" : 1505, "message" : "too many joins." }, 
  "ERROR_QUERY_COLLECTION_NAME_INVALID" : { "code" : 1506, "message" : "collection name '%s' is invalid" }, 
  "ERROR_QUERY_COLLECTION_ALIAS_INVALID" : { "code" : 1507, "message" : "collection alias '%s' is invalid" }, 
  "ERROR_QUERY_COLLECTION_ALIAS_REDECLARED" : { "code" : 1508, "message" : "collection alias '%s' is declared multiple times in the same query" }, 
  "ERROR_QUERY_COLLECTION_ALIAS_UNDECLARED" : { "code" : 1509, "message" : "collection alias '%s' is used but was not declared in the from clause" }, 
  "ERROR_QUERY_COLLECTION_NOT_FOUND" : { "code" : 1510, "message" : "unable to open collection '%s'" }, 
  "ERROR_QUERY_GEO_RESTRICTION_INVALID" : { "code" : 1511, "message" : "geo restriction for alias '%s' is invalid" }, 
  "ERROR_QUERY_GEO_INDEX_MISSING" : { "code" : 1512, "message" : "no suitable geo index found for geo restriction on '%s'" }, 
  "ERROR_QUERY_BIND_PARAMETER_MISSING" : { "code" : 1513, "message" : "no value specified for declared bind parameter '%s'" }, 
  "ERROR_QUERY_BIND_PARAMETER_REDECLARED" : { "code" : 1514, "message" : "value for bind parameter '%s' is declared multiple times" }, 
  "ERROR_QUERY_BIND_PARAMETER_UNDECLARED" : { "code" : 1515, "message" : "bind parameter '%s' was not declared in the query" }, 
  "ERROR_QUERY_BIND_PARAMETER_VALUE_INVALID" : { "code" : 1516, "message" : "invalid value for bind parameter '%s'" }, 
  "ERROR_QUERY_BIND_PARAMETER_NUMBER_OUT_OF_RANGE" : { "code" : 1517, "message" : "bind parameter number '%s' out of range" }, 
  "ERROR_QUERY_FUNCTION_NAME_UNKNOWN" : { "code" : 1518, "message" : "usage of unknown function '%s'" }, 
  "ERROR_QUERY_RUNTIME_ERROR"    : { "code" : 1520, "message" : "runtime error in query" }, 
  "ERROR_QUERY_LIMIT_VALUE_OUT_OF_RANGE" : { "code" : 1521, "message" : "limit value '%s' is out of range" }, 
  "ERROR_QUERY_VARIABLE_REDECLARED" : { "code" : 1522, "message" : "variable '%s' is assigned multiple times" }, 
  "ERROR_QUERY_DOCUMENT_ATTRIBUTE_REDECLARED" : { "code" : 1523, "message" : "document attribute '%s' is assigned multiple times" }, 
  "ERROR_QUERY_VARIABLE_NAME_INVALID" : { "code" : 1524, "message" : "variable name '%s' has an invalid format" }, 
  "ERROR_QUERY_BIND_PARAMETERS_INVALID" : { "code" : 1525, "message" : "invalid structure of bind parameters" }, 
  "ERROR_CURSOR_NOT_FOUND"       : { "code" : 1600, "message" : "cursor not found" }, 
  "ERROR_SESSION_USERHANDLER_URL_INVALID" : { "code" : 1700, "message" : "expecting <prefix>/user/<username>" }, 
  "ERROR_SESSION_USERHANDLER_CANNOT_CREATE_USER" : { "code" : 1701, "message" : "cannot create user" }, 
  "ERROR_SESSION_USERHANDLER_ROLE_NOT_FOUND" : { "code" : 1702, "message" : "role not found" }, 
  "ERROR_SESSION_USERHANDLER_NO_CREATE_PERMISSION" : { "code" : 1703, "message" : "no permission to create user with that role" }, 
  "ERROR_SESSION_USERHANDLER_USER_NOT_FOUND" : { "code" : 1704, "message" : "user not found" }, 
  "ERROR_SESSION_USERHANDLER_CANNOT_CHANGE_PW" : { "code" : 1705, "message" : "cannot manage password for user" }, 
  "ERROR_SESSION_SESSIONHANDLER_URL_INVALID1" : { "code" : 1706, "message" : "expecting POST <prefix>/session" }, 
  "ERROR_SESSION_SESSIONHANDLER_URL_INVALID2" : { "code" : 1707, "message" : "expecting GET <prefix>/session/<sid>" }, 
  "ERROR_SESSION_SESSIONHANDLER_URL_INVALID3" : { "code" : 1708, "message" : "expecting PUT <prefix>/session/<sid>/<method>" }, 
  "ERROR_SESSION_SESSIONHANDLER_URL_INVALID4" : { "code" : 1709, "message" : "expecting DELETE <prefix>/session/<sid>" }, 
  "ERROR_SESSION_SESSIONHANDLER_SESSION_UNKNOWN" : { "code" : 1710, "message" : "unknown session" }, 
  "ERROR_SESSION_SESSIONHANDLER_SESSION_NOT_BOUND" : { "code" : 1711, "message" : "session has not bound to user" }, 
  "ERROR_SESSION_SESSIONHANDLER_CANNOT_LOGIN" : { "code" : 1712, "message" : "cannot login with session" }, 
  "ERROR_SESSION_USERSHANDLER_INVALID_URL" : { "code" : 1713, "message" : "expecting GET <prefix>/users" }, 
  "ERROR_SESSION_DIRECTORYSERVER_INVALID_URL" : { "code" : 1714, "message" : "expecting /directory/sessionvoc/<token>" }, 
  "ERROR_SESSION_DIRECTORYSERVER_NOT_CONFIGURED" : { "code" : 1715, "message" : "directory server is not configured" }, 
  "ERROR_KEYVALUE_INVALID_KEY"   : { "code" : 1800, "message" : "invalid key declaration" }, 
  "ERROR_KEYVALUE_KEY_EXISTS"    : { "code" : 1801, "message" : "key already exists" }, 
  "ERROR_KEYVALUE_KEY_NOT_FOUND" : { "code" : 1802, "message" : "key not found" }, 
  "ERROR_KEYVALUE_KEY_NOT_UNIQUE" : { "code" : 1803, "message" : "key is not unique" }, 
  "ERROR_KEYVALUE_KEY_NOT_CHANGED" : { "code" : 1804, "message" : "key value not changed" }, 
  "ERROR_KEYVALUE_KEY_NOT_REMOVED" : { "code" : 1805, "message" : "key value not removed" }, 
  "ERROR_GRAPH_INVALID_GRAPH"    : { "code" : 1901, "message" : "invalid graph" }, 
  "ERROR_GRAPH_COULD_NOT_CREATE_GRAPH" : { "code" : 1902, "message" : "could not create graph" }, 
  "ERROR_GRAPH_INVALID_VERTEX"   : { "code" : 1903, "message" : "invalid vertex" }, 
  "ERROR_GRAPH_COULD_NOT_CREATE_VERTEX" : { "code" : 1904, "message" : "could not create vertex" }, 
  "ERROR_GRAPH_INVALID_EDGE"     : { "code" : 1905, "message" : "invalid edge" }, 
  "ERROR_GRAPH_COULD_NOT_CREATE_EDGE" : { "code" : 1906, "message" : "could not create edge" }, 
  "SIMPLE_CLIENT_UNKNOWN_ERROR"  : { "code" : 2000, "message" : "unknown client error" }, 
  "SIMPLE_CLIENT_COULD_NOT_CONNECT" : { "code" : 2001, "message" : "could not connect to server" }, 
  "SIMPLE_CLIENT_COULD_NOT_WRITE" : { "code" : 2002, "message" : "could not write to server" }, 
  "SIMPLE_CLIENT_COULD_NOT_READ" : { "code" : 2003, "message" : "could not read from server" }, 
  "ERROR_AVOCADO_INDEX_PQ_INSERT_FAILED" : { "code" : 3100, "message" : "priority queue insert failure" }, 
  "ERROR_AVOCADO_INDEX_PQ_REMOVE_FAILED" : { "code" : 3110, "message" : "priority queue remove failure" }, 
  "ERROR_AVOCADO_INDEX_PQ_REMOVE_ITEM_MISSING" : { "code" : 3111, "message" : "priority queue remove failure - item missing in index" }, 
};

