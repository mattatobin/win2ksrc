#include "priv.h"
#include "resource.h"
#include "itbar.h"
#include "itbdrop.h"

#include <stdlib.h>
#include <stdio.h>

struct valstr {
    int     val;
    char *  str;
};

#define TABENT(id)  { id, # id },
struct valstr ValStrTab[] = {
    // these guys come from doing:
    // qgrep IDM_ *.h unicpp/*.h ../inc/*.h
    // qgrep DVM_ *.h unicpp/*.h ../inc/*.h
    // magic editor commands to change to the right format:
    //  g/#define/s/.*#define /TABENT(/
    //  g/TABENT/s/\([^ ]*\).*/\1)/

#if 0
    // itbar.h
    TABENT(CITIDM_ONINTERNET)
    TABENT(CITIDM_THEATER)
    TABENT(CITIDM_TEXTLABELS)
    TABENT(CITIDM_VIEWTOOLS)
    TABENT(CITIDM_VIEWADDRESS)
    TABENT(CITIDM_VIEWLINKS)
    TABENT(CITIDM_SHOWTOOLS)
    TABENT(CITIDM_SHOWADDRESS)
    TABENT(CITIDM_SHOWLINKS)
    TABENT(CITIDM_EDITPAGE)
    TABENT(CITIDM_BRANDSIZE)
    TABENT(CITIDM_VIEWMENU)
    TABENT(CITIDM_VIEWAUTOHIDE)
    TABENT(CITIDM_GETMINROWHEIGHT)
    TABENT(CITIDM_SHOWMENU)
    TABENT(CITIDM_STATUSCHANGED)
    TABENT(CITIDM_GETDEFAULTBRANDCOLOR)
    TABENT(CITIDM_DISABLESHOWMENU)
    TABENT(CITIDM_SET_DIRTYBIT)
    TABENT(CITIDM_VIEWTOOLBARCUSTOMIZE)
#endif
    // itbdrop.h
    TABENT(TBIDM_BACK)
    TABENT(TBIDM_FORWARD)
    TABENT(TBIDM_HOME)
    TABENT(TBIDM_SEARCH)
    TABENT(TBIDM_STOPDOWNLOAD)
    TABENT(TBIDM_REFRESH)
    TABENT(TBIDM_FAVORITES)
#ifdef TBIDM_PRINT // old-style (pre-chee) toolbar
    TABENT(TBIDM_PRINT)
#endif
    TABENT(TBIDM_THEATER)
#ifdef TBIDM_PRINT
    TABENT(TBIDM_EDIT)
    TABENT(TBIDM_SHOWTOOLS)
    TABENT(TBIDM_HIDETOOLS)
    TABENT(TBIDM_MAILNEWS)
    TABENT(TBIDM_FONTS)
#endif
    TABENT(TBIDM_HISTORY)
#if defined(ENABLE_CHANNELS) && defined(TBIDM_CHANNELS)
    TABENT(TBIDM_CHANNELS)
#endif
#ifdef TBIDM_PRINT
    TABENT(TBIDM_QUICKLINK1)
    TABENT(TBIDM_QUICKLINK2)
    TABENT(TBIDM_QUICKLINK3)
    TABENT(TBIDM_QUICKLINK4)
    TABENT(TBIDM_QUICKLINK5)
#endif
    // resource.h
    TABENT(BSIDM_CLOSEBAND)
    TABENT(BSIDM_SHOWTITLEBAND)
    TABENT(BSIDM_IEAK_DISABLE_DDCLOSE)
    TABENT(BSIDM_IEAK_DISABLE_MOVE)
    TABENT(ISFBIDM_LARGE)
    TABENT(ISFBIDM_SMALL)
    TABENT(ISFBIDM_LOGOS)
    TABENT(ISFBIDM_SHOWTEXT)
    TABENT(ISFBIDM_REFRESH)
    TABENT(ISFBIDM_OPEN)
    TABENT(DBIDM_NEWFOLDERBAND)
    TABENT(DBIDM_DESKTOPBAND)
    TABENT(DBIDM_LAUNCHBAND)
    TABENT(DBIDM_NEWBANDFIXEDLAST)
    TABENT(MNIDM_RESORT)
    TABENT(MNIDM_LAST)
    TABENT(IDM_AB_FIRST)
    TABENT(IDM_AB_LEFT)
    TABENT(IDM_AB_TOP)
    TABENT(IDM_AB_RIGHT)
    TABENT(IDM_AB_BOTTOM)
    TABENT(IDM_AB_BOTTOMMOST)
    TABENT(IDM_AB_TOPMOST)
    TABENT(IDM_AB_REGULAR)
    TABENT(IDM_AB_AUTOHIDE)
    TABENT(IDM_AB_CLOSE)
    TABENT(IDM_AB_ENABLEMODELESS)
    TABENT(IDM_AB_DISABLEMODELESS)
    TABENT(IDM_AB_ACTIVATE)
    TABENT(IDM_AB_LAST)
    TABENT(DVIDM_GOHOME)
    TABENT(FCIDM_DROPDRIVELIST)
    TABENT(DVIDM_OPEN)
    TABENT(DVIDM_SAVE)
    TABENT(DVIDM_SAVEASFILE)
    TABENT(DVIDM_PAGESETUP)
    TABENT(DVIDM_PRINT)
    TABENT(DVIDM_PROPERTIES)
    TABENT(DVIDM_CUT)
    TABENT(DVIDM_COPY)
    TABENT(DVIDM_PASTE)
    TABENT(DVIDM_REFRESH)
    TABENT(DVIDM_STOPDOWNLOAD)
    TABENT(DVIDM_ZOOMIN)
    TABENT(DVIDM_ZOOMOUT)
    TABENT(DVIDM_NEWWINDOW)
    TABENT(DVIDM_NEWMESSAGE)
    TABENT(DVIDM_SEND)
    TABENT(DVIDM_SENDPAGE)
    TABENT(DVIDM_SENDSHORTCUT)
    TABENT(DVIDM_DESKTOPSHORTCUT)
    TABENT(DVIDM_SENDTO)
    TABENT(DVIDM_SENDTOFIRST)
    TABENT(DVIDM_SENDTOLAST)
    TABENT(DVIDM_HELPABOUT)
    TABENT(DVIDM_HELPSEARCH)
    TABENT(DVIDM_HELPTUTORIAL)
    TABENT(DVIDM_HELPMSWEB)
    TABENT(DVIDM_HELPREPAIR)
    TABENT(DVIDM_HELPMSWEBLAST)
    TABENT(DVIDM_SUITE_APP_FIRST)
    TABENT(DVIDM_NEW)
    TABENT(DVIDM_NEWPOST)
    TABENT(DVIDM_NEWAPPOINTMENT)
    TABENT(DVIDM_NEWMEETING)
    TABENT(DVIDM_NEWCONTACT)
    TABENT(DVIDM_NEWTASK)
    TABENT(DVIDM_NEWTASKREQUEST)
    TABENT(DVIDM_NEWJOURNAL)
    TABENT(DVIDM_NEWNOTE)
    TABENT(DVIDM_CALL)
    TABENT(DVIDM_SUITE_APP_LAST)
    TABENT(DVIDM_NONSUITE_APP_FIRST)
    TABENT(DVIDM_NONSUITE_APP_LAST)
    TABENT(DVIDM_MSHTML_FIRST)
    TABENT(DVIDM_MSHTML_LAST)
    TABENT(FCIDM_FIRST)
    TABENT(FCIDM_LAST)
    TABENT(FCIDM_BROWSER_FILE)
    TABENT(FCIDM_FILECLOSE)
    TABENT(FCIDM_PREVIOUSFOLDER)
    TABENT(FCIDM_DELETE)
    TABENT(FCIDM_RENAME)
    TABENT(FCIDM_PROPERTIES)
    TABENT(FCIDM_VIEWOFFLINE)
    TABENT(FCIDM_FILENSCBANDSEP)
    // IE4 shipped with FCIDM_NEXTCTL as 0xA030 and we can not change it
    TABENT(FCIDM_NEXTCTL)
    TABENT(FCIDM_BACKSPACE)
#ifdef TEST_AMBIENTS
    TABENT(FCIDM_VIEWLOCALOFFLINE)
    TABENT(FCIDM_VIEWLOCALSILENT)
#endif
    TABENT(FCIDM_BROWSER_EDIT)
    TABENT(FCIDM_MOVE)
    TABENT(FCIDM_COPY)
    TABENT(FCIDM_PASTE)
    TABENT(FCIDM_SELECTALL)
    TABENT(FCIDM_LINK)
    TABENT(FCIDM_EDITPAGE)
    // BUGBUG:: IOmega relies on FCIDM_REFRESH was WM_COMMAND of A065
    TABENT(FCIDM_W95REFRESH)
    TABENT(FCIDM_BROWSER_TOOLS)
    TABENT(FCIDM_CONNECT)
    TABENT(FCIDM_DISCONNECT)
    TABENT(FCIDM_CONNECT_SEP)
    TABENT(FCIDM_GETSTATUSBAR)
    // IE4 shipped with FCIDM_FINDFILES as 0xA0085 and we can not change it
    TABENT(FCIDM_FINDFILES)
    // IE4 shipped with FCIDM_FINDFILES as 0xA0086 and we can not change it
    TABENT(FCIDM_FINDCOMPUTER)
    TABENT(FCIDM_SETSTATUSBAR)
    TABENT(FCIDM_PERSISTTOOLBAR)
    TABENT(FCIDM_MENU_TOOLS_FINDFIRST)
    TABENT(FCIDM_MENU_TOOLS_FINDLAST)
    TABENT(FCIDM_BROWSER_HELP)
    TABENT(FCIDM_HELPSEARCH)
    TABENT(FCIDM_HELPABOUT)
    TABENT(FCIDM_BROWSER_EXPLORE)
    TABENT(FCIDM_NAVIGATEBACK)
    TABENT(FCIDM_NAVIGATEFORWARD)
    TABENT(FCIDM_BROWSEROPTIONS)
    TABENT(FCIDM_LINKSSEPARATOR)
    TABENT(FCIDM_STARTPAGE)
    TABENT(FCIDM_UPDATEPAGE)
    TABENT(FCIDM_CHANNELGUIDE)
    TABENT(FCIDM_MAIL)
    TABENT(FCIDM_NEWS)
    TABENT(FCIDM_MAILNEWSSEPARATOR)
    TABENT(FCIDM_NEWMESSAGE)
    TABENT(FCIDM_SENDLINK)
    TABENT(FCIDM_SENDDOCUMENT)
    TABENT(FCIDM_SEARCHSIMILAR)
    TABENT(FCIDM_OPEN_SUBSCRIPTION)
    TABENT(FCIDM_MYCOMPUTER)
    TABENT(FCIDM_SEARCHMENU)
    TABENT(FCIDM_RECENTFIRST)
    TABENT(FCIDM_RECENTLAST)
    TABENT(FCIDM_RECENTMENU)
    TABENT(FCIDM_FAVS_FIRST)
    TABENT(FCIDM_ORGANIZEFAVORITES)
    TABENT(FCIDM_ADDTOFAVORITES)
    TABENT(FCIDM_FAVS_MORE)
    TABENT(FCIDM_FAVORITEFIRST)
    TABENT(FCIDM_UPDATESUBSCRIPTIONS)
    TABENT(FCIDM_SORTBY)
    TABENT(FCIDM_SORTBYNAME)
    TABENT(FCIDM_SORTBYVISIT)
    TABENT(FCIDM_SORTBYDATE)
    TABENT(FCIDM_FAVAUTOARRANGE)
    TABENT(FCIDM_SUBSCRIPTIONS)
    TABENT(FCIDM_SUBSCRIBE)
    TABENT(FCIDM_FAVORITELAST)
    TABENT(FCIDM_FAVORITE_ITEM)
    TABENT(FCIDM_FAVORITECMDFIRST)
    TABENT(FCIDM_FAVORITECMDLAST)
    TABENT(FCIDM_FAVS_LAST)
    TABENT(FCIDM_BROWSER_VIEW)
    TABENT(FCIDM_VIEWTOOLBAR)
    TABENT(FCIDM_VIEWSTATUSBAR)
    TABENT(FCIDM_VIEWOPTIONS)
    TABENT(FCIDM_VIEWTOOLS)
    TABENT(FCIDM_VIEWADDRESS)
    TABENT(FCIDM_VIEWLINKS)
    TABENT(FCIDM_VIEWTEXTLABELS)
#ifdef TBIDM_PRINT
    TABENT(FCIDM_VIEWTBCUST)
#endif
    TABENT(FCIDM_VIEWAUTOHIDE)
    TABENT(FCIDM_VIEWMENU)
    TABENT(FCIDM_STOP)
    TABENT(FCIDM_VIEWTREE)
    TABENT(FCIDM_VIEWSEARCH)
    TABENT(FCIDM_CUSTOMIZEFOLDER)
    TABENT(FCIDM_VIEWFONTS)
    // 1a is FCIDM_STOP
    TABENT(FCIDM_THEATER)
    TABENT(FCIDM_JAVACONSOLE)
    TABENT(FCIDM_VIEWTOOLBARCUSTOMIZE)
    TABENT(FCIDM_REFRESH)
    TABENT(FCIDM_ADDTOFAVNOUI)
    TABENT(FCIDM_VIEWITBAR)
    TABENT(FCIDM_SEARCHFIRST)
    TABENT(FCIDM_SEARCHLAST)
#ifdef FCIDM_PERFOLDERSEARCHFIRST
    TABENT(FCIDM_PERFOLDERSEARCHFIRST)
    TABENT(FCIDM_PERFOLDERSEARCHLAST)
#endif
    TABENT(FCIDM_VIEWBROWSERBARS)
    TABENT(FCIDM_VBBSEARCHBAND)
    TABENT(FCIDM_VBBFAVORITESBAND)
    TABENT(FCIDM_VBBHISTORYBAND)
#if defined(ENABLE_CHANNELS) && defined(FCIDM_VBBCHANNELSBAND)
    TABENT(FCIDM_VBBCHANNELSBAND)
#endif
    TABENT(FCIDM_VBBEXPLORERBAND)
    TABENT(FCIDM_VBBALL)
#ifdef FCIDM_VBBNONE
    TABENT(FCIDM_VBBNONE)
#endif
    TABENT(FCIDM_VBBFIXFIRST)
    TABENT(FCIDM_VBBFIXLAST)
    TABENT(FCIDM_VBBDYNFIRST)
    TABENT(FCIDM_VBBDYNLAST)
    TABENT(IDM_AC_FIRST)
    TABENT(IDM_AC_UNDO)
    TABENT(IDM_AC_CUT)
    TABENT(IDM_AC_COPY)
    TABENT(IDM_AC_PASTE)
    TABENT(IDM_AC_DELETE)
    TABENT(IDM_AC_SELECTALL)
    TABENT(IDM_AC_COMPLETIONS)
    TABENT(IDM_AC_FIRSTCOMPITEM)
    TABENT(IDM_AC_LASTCOMPITEM)
    TABENT(FCIDM_APPS_FIRST)
    TABENT(FCIDM_CONTACTS)
    TABENT(FCIDM_CALENDAR)
    TABENT(FCIDM_TASKS)
    TABENT(FCIDM_JOURNAL)
    TABENT(FCIDM_NOTES)
    TABENT(FCIDM_CALL)
    TABENT(FCIDM_APPS_LAST)
    TABENT(FCIDM_FILECTX_FIRST)
    TABENT(FCIDM_FILECTX_LAST)
    TABENT(FSIDM_NEWFOLDER)
    TABENT(FSIDM_NEWLINK)
    TABENT(FSIDM_NEWOTHER)
    TABENT(IDM_BROWBAND_REFRESH)
    TABENT(IDM_BROWBAND_OPENNEW)
};
#undef TABENT

void PrTab(struct valstr *pvs, int n);

int _cdecl main()
{
    PrTab(ValStrTab, ARRAYSIZE(ValStrTab));
    return 0;
}

void PrTab(struct valstr *pvs, int n)
{
    for (; n > 0; n--, pvs++) {
        printf("%s\t0x%x\r\n", pvs->str, pvs->val);
    }
    return;
}
