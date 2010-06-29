; $Id: profiler_example.profiler.inc,v 1.1 2010/03/24 00:39:09 q0rban Exp $

; -----------------------------------------------------------------------------
; A list of all the parent items:
;
; - modules
; - modules-unset (This comes in handy for Sub Profiler includes, as you can 
;                 unset modules that are set by the base Profiler include here)
; - features
; - features-unset (@see modules-unset)
; - roles
; - users
; - input-formats
; - variables
; - permissions
; - node-types
; - nodes
; - menus
; - menu-items
; - blocks
; -----------------------------------------------------------------------------

name = Lullabot Core
core = 6.x
theme = zen


; -----------------------------------------------------------------------------
; You could specify this as a base Profiler include by using the following in
; your own Install profile's Profiler include. Then everything in this file
; would be merged with your Profiler include:
; -----------------------------------------------------------------------------
;base = profiler_example


; -----------------------------------------------------------------------------
;                                  Modules
; -----------------------------------------------------------------------------
; Break out your modules into separate arrays, 'code' and 'contrib' as follows.
; You can create your own arrays as well, such as 'custom'. Any other arrays
; will get installed at the same time as all contrib modules do.
; -----------------------------------------------------------------------------
modules[core][] = filter
modules[core][] = help
modules[core][] = menu
modules[core][] = node
modules[core][] = path
modules[core][] = system
modules[core][] = user

; Contrib
modules[contrib][] = admin_menu
modules[contrib][] = date_api
modules[contrib][] = imageapi
modules[contrib][] = imageapi_gd
modules[contrib][] = imagecache
modules[contrib][] = token
modules[contrib][] = globalredirect
modules[contrib][] = content
modules[contrib][] = fieldgroup
modules[contrib][] = filefield
modules[contrib][] = imagefield
modules[contrib][] = number
modules[contrib][] = optionwidgets
modules[contrib][] = text
modules[contrib][] = views
modules[contrib][] = advanced_help
modules[contrib][] = features
modules[contrib][] = pathauto
modules[contrib][] = wysiwyg
modules[contrib][] = markdown
modules[contrib][] = transliteration


; -----------------------------------------------------------------------------
;                                  Features
; -----------------------------------------------------------------------------
; Specify features thusly:
;features[] = example_feature


; -----------------------------------------------------------------------------
;                                   Roles
; -----------------------------------------------------------------------------
; Roles are kinda tricky, because the role ids are what makes them work, yet 
; role ids are given in the order in which the roles are created. For this 
; reason there are two ways of specifying roles here. You can either just make 
; an array of roles with the values being the name of the role, or you can make 
; the value be a nested array and specify the role id manually. Take care when 
; using this latter method. Role id's 1 and 2 are reserved in Drupal.
;
; Note how a text key ('admin' & 'publisher') is used in both instances. This 
; isn't strictly necessary, as you could just empty brackets (roles[] = administrator),
; however if you create a Sub-Profiler include based off this include, you 
; wouldn't have a way of overriding these values if you needed to. Best to use 
; text keys just in case.
; -----------------------------------------------------------------------------

roles[administrator] = administrator
roles[editor] = Editor

; -----------------------------------------------------------------------------
;                                   Users
; -----------------------------------------------------------------------------
; Keep in mind when adding users like this that you are proceeding at your own
; risk. You are writing *in plain text* certain data that could compromise your 
; site. The password field you specify for any user should be an md5 hashed 
; password. I guess that gives you at least one measure of security.
;
; One other thing to note here is that there's this (handy) quirk in Drupal's 
; install API in that you can bypass the configuration form during installation
; (where you'd normally set up user 1 credentials and the site name and such).
; To do this you need to specify credentials for user 1 and also specify the
; site name and site email variables (@see Variables below). 
; -----------------------------------------------------------------------------



; -----------------------------------------------------------------------------
;                                Input Formats
; -----------------------------------------------------------------------------
; Input formats get a little tricky because of these deep nested arrays. The
; first level of the array is just an internal machine name of the filter. You 
; can set this to anything you like, but don't leave empty brackets, or you'll 
; be sorry ;).
;
; For each input format you can set name, roles, filters, allowed-html, wysiwyg 
; (for use with the Wysiwyg API module), and default (set this to 1 on the 
; input format you want to be the default input format).
;
; The filters array is a little tricky as you need to know the 'delta' of each
; input filter, and the module that exposes that filter. Once you know that, 
; the structure is then [filters][MODULE][DELTA] = WEIGHT
;
; The roles key is just a comma separated list of the roles that have access to
; this input format. Be sure to use the correct name exactly!
;
; So if you thought filters was confusing, wysiwyg is even more so. Hopefully
; the example I've outlined below will bring clarity.
; -----------------------------------------------------------------------------

input-formats[markdown][name] = Markdown
input-formats[markdown][default] = 1
input-formats[markdown][roles] = anonymous user,authenticated user
input-formats[markdown][filters][markdown][0] = -10
input-formats[markdown][filters][filter][0] = -7
input-formats[markdown][filters][filter][1] = -8
input-formats[markdown][filters][filter][2] = -9
input-formats[markdown][filters][filter][3] = -6
input-formats[markdown][allowed-html] = "<a> <p> <em> <strong> <span> <h1> <h2> <h3> <h4> <h5> <blockquote> <cite> <code> <ul> <ol> <li> <dl> <dt> <dd> <img> <table> <thead> <tbody> <tfoot> <th> <tr> <td>"

input-formats[wysiwyg][name] = WYSIWYG
input-formats[wysiwyg][roles] = administrator,publisher
input-formats[wysiwyg][filters][filter][0] = -8
input-formats[wysiwyg][filters][filter][1] = -7
input-formats[wysiwyg][filters][filter][2] = -9
input-formats[wysiwyg][filters][filter][3] = -6
input-formats[wysiwyg][allowed-html] = "<a> <p> <em> <strong> <span> <h1> <h2> <h3> <h4> <h5> <blockquote> <cite> <code> <ul> <ol> <li> <dl> <dt> <dd> <img> <table> <thead> <tbody> <tfoot> <th> <tr> <td>"
input-formats[wysiwyg][wysiwyg][editor] = tinymce
input-formats[wysiwyg][wysiwyg][settings][default] = 1
input-formats[wysiwyg][wysiwyg][settings][user_choose] = 0
input-formats[wysiwyg][wysiwyg][settings][show_toggle] = 0
input-formats[wysiwyg][wysiwyg][settings][theme] = advanced
input-formats[wysiwyg][wysiwyg][settings][language] = en
input-formats[wysiwyg][wysiwyg][settings][buttons][default][bold] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][italic] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][underline] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][bullist] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][numlist] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][outdent] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][indent] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][link] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][unlink] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][default][image] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][paste][pastetext] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][font][formatselect] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][font][styleselect] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][table][tablecontrols] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][safari][safari] = 1
input-formats[wysiwyg][wysiwyg][settings][buttons][imce][imce] = 1
input-formats[wysiwyg][wysiwyg][settings][toolbar_loc] = top
input-formats[wysiwyg][wysiwyg][settings][toolbar_align] = left
input-formats[wysiwyg][wysiwyg][settings][path_loc] = bottom
input-formats[wysiwyg][wysiwyg][settings][resizing] = 1
input-formats[wysiwyg][wysiwyg][settings][verify_html] = 1
input-formats[wysiwyg][wysiwyg][settings][preformatted] = 0
input-formats[wysiwyg][wysiwyg][settings][convert_fonts_to_spans] = 1
input-formats[wysiwyg][wysiwyg][settings][remove_linebreaks] = 1
input-formats[wysiwyg][wysiwyg][settings][apply_source_formatting] = 0
input-formats[wysiwyg][wysiwyg][settings][paste_auto_cleanup_on_paste] = 0
input-formats[wysiwyg][wysiwyg][settings][block_formats] = p,h2,h3,h4,h5,blockquote
input-formats[WYSIWYG][wysiwyg][settings][css_classes] = "Highlight=highlight
Float Left=left
Float Right=right"


; -----------------------------------------------------------------------------
;                                  Variables
; -----------------------------------------------------------------------------
; These variables should be pretty self explanatory, as they are just an array
; of key value pairs for items in the variable table. Nested arrays also can 
; crop up here, since variables can be arrays.
;
; Also, make note of the site_name and site_mail variables below. These 
; variables need to be set if you want to bypass the Configuration form during 
; installation (@see Users for more information on how this is accomplished).
; -----------------------------------------------------------------------------
variables[site_name] = Lullabot Loves You!
variables[theme_settings][toggle_node_info_page] = 0


; -----------------------------------------------------------------------------
;                                 Permissions
; -----------------------------------------------------------------------------
permissions[access administration pages] = administrator,publisher
permissions[access content] = anonymous user,authenticated user
permissions[access user profiles] = administrator
permissions[administer menu] = administrator,publisher
permissions[administer nodes] = administrator,publisher
permissions[administer site configuration] = administrator
permissions[administer users] = administrator
permissions[change own username] = authenticated user
permissions[create page content] = administrator,publisher
permissions[create users] = administrator
permissions[delete any page content] = administrator,publisher
permissions[delete own page content] = administrator,publisher
permissions[edit any page content] = administrator,publisher
permissions[flush imagecache] = administrator
permissions[notify of path changes] = administrator,publisher
permissions[search content] = anonymous user


; -----------------------------------------------------------------------------
;                                 Nodes types
; -----------------------------------------------------------------------------
node-types[page][type] = page
node-types[page][name] = Page
node-types[page][has_body] = 1
node-types[page][body_label] = Body
node-types[page][module] = node
node-types[page][description] = A <em>page</em> is simply what it sounds like - it's a page on your website.
node-types[page][custom] = 1
node-types[page][modified] = 1
node-types[page][locked] = 0
node-types[page][help] = ''
node-types[page][min_word_count] = ''


; -----------------------------------------------------------------------------
;                                    Nodes
; -----------------------------------------------------------------------------
;nodes[front][type] = page
;nodes[front][title] = Isn't Profiler nifty?
;nodes[front][uid] = 2
;nodes[front][body] = <p>Donec vel ipsum elit. In rutrum, ante at fringilla pharetra, mi justo fermentum risus; eget commodo est mi lobortis augue. Proin fringilla malesuada semper. Ut velit sapien, condimentum vel faucibus ut, aliquam quis dui? Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Vivamus vulputate fringilla enim, non convallis nibh lacinia at. Etiam fermentum, lectus ac sagittis volutpat, est augue tincidunt mi, et consectetur orci nisi sit amet sapien. Ut nisi nunc, molestie quis sollicitudin at, dignissim eget nisl? Sed vitae sem lectus. Curabitur viverra laoreet magna. Sed eget sapien tellus, eu tempor purus. Proin dignissim, lacus vitae venenatis porttitor, justo libero rhoncus felis, nec dictum nisl mi vitae nisi. Maecenas tincidunt eros at turpis sollicitudin nec viverra enim condimentum. Sed nec enim justo. In tristique risus dui; ac egestas mi. Proin at arcu sed enim eleifend ornare eu at arcu. Curabitur ullamcorper, ipsum eu imperdiet pharetra, mauris lorem hendrerit metus, in consectetur mauris est iaculis eros. Quisque euismod hendrerit metus ullamcorper tempus! Cras gravida ornare arcu vitae commodo. In hac habitasse platea turpis duis.</p>


; -----------------------------------------------------------------------------
;                                   Menus
; -----------------------------------------------------------------------------

; Create a new menu called Footer Links.
menus[menu-footer-links][title] = Footer Links

; Now add some Menu items to existing menus.
menu-items[login][link_path]  = user/login
menu-items[login][link_title] = Login
menu-items[login][weight]     = 10
menu-items[login][menu_name]  = menu-footer-links

menu-items[logout][link_path]  = logout
menu-items[logout][link_title] = Logout
menu-items[logout][weight]     = 10
menu-items[logout][menu_name]  = menu-footer-links

menu-items[front][link_path]  = <front>
menu-items[front][link_title] = Home
menu-items[front][weight]     = -10
menu-items[front][menu_name]  = primary-links


; -----------------------------------------------------------------------------
;                                   Blocks
; -----------------------------------------------------------------------------
; blocks[menu-menu-footer-links][module] = menu
; blocks[menu-menu-footer-links][delta] = menu-footer-links
; blocks[menu-menu-footer-links][region] = right
