API Module
Generates and displays API documentation pages.

GENERAL INFORMATION

This is an implementation of a subset of the Doxygen documentation generator
specification, tuned to produce output that best benefits the Drupal code base.
It is designed to assume the code it documents follows Drupal coding
conventions, and supports Doxygen constructs as documented on
http://drupal.org/node/1354.

In addition to standard Doxygen syntax requirements, the following restrictions
are made on the code format. These are all Drupal coding conventions (see
http://drupal.org/node/1354 for more details and suggestions).

1. All documentation blocks must use the syntax:

/**
 * Documentation here.
 */

The leading spaces are required.

2. When documenting a function, constant, class, etc., the documentation block
   must immediately precede the item it documents, with no intervening blank
   lines.

3. There may be no intervening spaces between a function name and the left
   parenthesis that follows it.

Besides the Doxygen features that are supported, this module also provides the
following features:

1. Functions may be in multiple groups (Doxygen ignores all but the first
   group). This allows, for example, theme_menu_tree() to be marked as both
   "themeable" and part of the "menu system".

2. Function calls to PHP library functions are linked to the PHP manual.

3. Function calls have tooltips briefly describing the called function.

4. Documentation pages have non-volatile, predictable URLs, so links to
   individual functions will not be invalidated when the number of functions in
   a document changes.

INSTALLATION AND SETUP

See http://drupal.org/node/1516558 for information on how to install and set up
this module.

SEARCH AND VIEWS INTEGRATION

If you enable the included "API Search Integration" module (machine name:
api_search), as well as either the Drupal Core "Search" module or the
contributed Apache Solr search module, you can perform full-text searches
on API documentation, just like your regular site content.

Note: If you already had Search and the API module installed and running on a
site, and then enabled the "API Search Integration" module, you will either
need to run a reparse of the API documentation, or a reindex of Search, in
order to get the full text of the API documentation into the search index.
But if you already had Search but not API, or API and not Search, and then
enable the other one plus the search integration module at the same time,
the API documentation will automatically be indexed for you over the next
cron runs.

The API documentation is also integrated with Views. Actually, most of the
listing pages for the API module use Views, and you should be able to clone
and modify these pages to make your own views if you want something different.
