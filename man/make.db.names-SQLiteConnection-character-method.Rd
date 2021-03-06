% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/deprecated.R
\docType{methods}
\name{make.db.names,SQLiteConnection,character-method}
\alias{make.db.names,SQLiteConnection,character-method}
\alias{SQLKeywords,SQLiteConnection-method}
\alias{isSQLKeyword,SQLiteConnection,character-method}
\title{Make R/S-Plus identifiers into legal SQL identifiers}
\usage{
\S4method{make.db.names}{SQLiteConnection,character}(dbObj, snames,
  keywords = .SQL92Keywords, unique = TRUE, allow.keywords = TRUE, ...)

\S4method{SQLKeywords}{SQLiteConnection}(dbObj, ...)

\S4method{isSQLKeyword}{SQLiteConnection,character}(dbObj, name,
  keywords = .SQL92Keywords, case = c("lower", "upper", "any")[3], ...)
}
\description{
Deprecated. Please use \code{\link[=dbQuoteIdentifier]{dbQuoteIdentifier()}} instead.
}
\keyword{internal}
