##HTML5
Table of Content
-----------------
1. [Introduction](#introduction)
1. [Support](#support)
1. [Elements](#elements)
1. [Semantics](#semantics)
1. [Migration](#migration)
1. [Style Guide)(#sytle guide)

Introduction
------------
###What is New in HTML5?
The DOCTYPE declaration for HTML5 is very simple:
```
<!DOCTYPE html>
```
The character encoding (charset) declaration is also very simple:
```
<meta charset="UTF-8">
```
Example:
```
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Title of the document</title>
	</head>
	<body>
		Content of the document.
	</body>
</html>
```

* The default charater encoding in HTML5 is UTF-8.

###New HTML5 Elements
The most interesting new HTML5 elements are:
* Semantic elements like <header>, <footer>, <article>, and <section>
* Attributes of form elements like number, date, time, calandar, and range.
* Graphic elements: <svg> and <canvas>
* Multimedia elements: <audio> and <video>

###New HTML5 API's
The most interesting new API's in HTML5 are:
* Geolocation
* Drag and Drop
* Local Storage
* Application Cache
* Web Worker
* SSE

###Removed Elements in HTML5
The following HTML4 elements have been removed in HTML5:
* &lt;acronym&gt;, use instead <abbr> (<abbr> be used from HTML4.0)
* <applet>, use instead <object>
* <basefont>, use CSS
* <big>, use CSS
* <center>, use CSS
* <dir>, use <ul>
* <font>, use CSS
* <frame>
* <frameset>
* <noframes>
* <strike>, use CSS, <s> or <del>
* <tt>, CSS

###HTML History
* 1989: Tim Berners-Lee invented www
* 1991: Tim Berners-Lee invented html
* 1993: Dave Raggett drafted HTML+
* 1995: HTML Working Group defined HTML2.0
* 1997: W3C Recommendation: HTML3
* 1999: W3C Recommendation: HTML 4.0.1
* 2000: W3C Recommendation: XHTML 1.0
* 2008: WHATWG HTML5 First Public Draft
* 2012: WHATWG HTML5 Living Standard
* 2014: W3C Recommendation: HTML5
* 2016: W3C Candidate Recommendation: HTML 5.1

Suport
------
###HTML5 Browser Support
HTML5 is supported in all modern browsers.
In addition, all browsers, old and new automatically handle unrecoginized elements as inline elements. Because of this, you can "teach" older browsers to handle unknown HTML elements.

###Define Semantic Elements as Block Elements
HTML5 defines eight new semantic elements. All these are block-level elements.
To secure correct behavior in older browsers, you can set the CSS display property for these HTML elements to block:
```
header, section, footer, aside, nav, main, article, figure {
	display: block;
}
```

###Add New Elements to HTML
You can also add new elements to HTML page with a browser trick. This example adds a new elementcall <myElement> to an HTML page, and defines a style for it:
```
<!DOCTYPE html>
<html>
	<head>
		<script>document.createElement("myElement")</script>
		<style>
			myElement {
				display: block:
				background-color: #ddd;
				padding: 50px;
				font-size: 30px;
			}
		</style>
	</head>
	<body>
		<h1>Header</h1>
		<myElement>My Element</myElement>
	</body>
</html>
```
The Javascript statement document.createElement("myElement") is needed to create a new element in IE 9, and earlier.

###Problem with IE8
IE 8 (and earlier) does not allow styling of unknown elements!
Sjoerd Visscher created the HTML5Shiv! The HTML5Shiv is a Javascript workaround to enable styling of HTML5 elements in versions of Internet Explorer prior to version 9.

Elements
--------
###New Semantic/Structural Elements
HTML5 offers new elements for better document structure:
* <article>: Define an article in the document
* <aside>: Define content aside from the page content
* <bdi>: Define a part of text that might be formatted in a different direction from other text
* <details>: Define additional details that the user can view or hide
* <dialog>: Define a dialog box or window
* <figcaption>: Define a caption for <figure> element
* <figure>: Define self-contained content, like illustrations, diagrams, photos, code listings, etc.
* <footer>: Define a footer for the document or section
* <header>: Define a header for the document or section
* <main>: Define the main content of a document
* <mark>: Define marked or highlighted text
* <menuitem>: Define a command/menu item that the user can invoke from a popup menu
* <meter>: Define a scalar measurement within a known range (a gauge)
* <nav>: Define navigation links in the document
* <progress>: Define the progress of task
* <rp>: Define what to show in browsers that do not support ruby annotations
* <rt>: Define an explanation/pronunciation of characters (for East Asian typograph)
* <ruby>: Define a ruby annotation (for East Asian typograph)
* <section>: Define a section in the document
* <summary>: Define a visible heading for a <detail> element
* <time>: Define a date/time
* <wbr>: Define a possible line-break

###New Form Elements
* <detalist>: Define pre-defined options for input controls
* <keygen>: Define a key-pair generator field (for forms)
* <output>: Define the result of a calculation

###New Input Types
* color
* date
* datetime
* datetime-local
* email
* month
* number
* range
* search
* tel
* time
* url
* week

###New Input Attributes
* autocomplete
* autofocus
* form
* formaction
* formenctype
* formmethod
* formnovalidate
* formtarget
* height and width
* list
* min and max
* multiple
* pattern (regexp)
* placeholder
* required
* step

###New Attribue Syntax
HTML5 allows four different syntaxes for attributes.
This example demonstrates the different syntaxes used in an <input> tag:
* Empty: <input type="text" value="John" disable>
* Unquoted: <input type="text" value=John>
* Double-quoted: <input type="text" value="John Doe">
* Single-quoted: <input type="text" value='John Doe'>

In HTML5, all four syntaxes may be used, depending on what is needed for the attribute.

###HTML5 Graphics
* <canvas>: Draw graphics, on the fly, via scripting (usually Javascript)
* <svg>: Draw scalable vector graphics

###New Media Elements
* <audio>: Define sound content
* <embed>: Define containers for external application (like plug-ins)
* <source>: Define sources for <video> and <audio>
* <track>: Define tracks for <video> and <audio>
* <video>: Define video or movie content
