#!/bin/bash

# Paths
LAYOUT_DEST="/usr/share/X11/xkb/symbols/clmk-dh"
EVDEV_XML="/usr/share/X11/xkb/rules/evdev.xml"

# Define the keyboard layout content
LAYOUT_CONTENT="
partial alphanumeric_keys
xkb_symbols "colemak-dh" {

    include "us"
    name[Group1]= "English (Colemak-DH)";

    key <TLDE> { [        grave,   asciitilde,      dead_tilde,       asciitilde ] };
    key <AE01> { [            1,       exclam,      exclamdown,      onesuperior ] };
    key <AE02> { [            2,           at,       masculine,      twosuperior ] };
    key <AE03> { [            3,   numbersign,     ordfeminine,    threesuperior ] };
    key <AE04> { [            4,       dollar,            cent,         sterling ] };
    key <AE05> { [            5,      percent,        EuroSign,              yen ] };
    key <AE06> { [            6,  asciicircum,         hstroke,          Hstroke ] };
    key <AE07> { [            7,    ampersand,             eth,              ETH ] };
    key <AE08> { [            8,     asterisk,           thorn,            THORN ] };
    key <AE09> { [            9,    parenleft,  leftsinglequotemark,  leftdoublequotemark ] };
    key <AE10> { [            0,   parenright, rightsinglequotemark,  rightdoublequotemark ] };
    key <AE11> { [        minus,   underscore,          endash,           emdash ] };
    key <AE12> { [        equal,         plus,        multiply,         division ] };

    key <AD01> { [            q,            Q,      adiaeresis,       Adiaeresis ] };
    key <AD02> { [            w,            W,           aring,            Aring ] };
    key <AD03> { [            f,            F,          atilde,           Atilde ] };
    key <AD04> { [            p,            P,          oslash,         Ooblique ] };
    key <AD05> { [            b,            B,      dead_breve,       asciitilde ] };
    key <AD06> { [            j,            J,         dstroke,          Dstroke ] };
    key <AD07> { [            l,            L,         lstroke,          Lstroke ] };
    key <AD08> { [            u,            U,          uacute,           Uacute ] };
    key <AD09> { [            y,            Y,      udiaeresis,       Udiaeresis ] };
    key <AD10> { [    semicolon,        colon,      odiaeresis,       Odiaeresis ] };
    key <AD11> { [  bracketleft,    braceleft,   guillemotleft,        0x1002039 ] };
    key <AD12> { [ bracketright,   braceright,  guillemotright,        0x100203a ] };
    key <BKSL> { [    backslash,          bar,      asciitilde,       asciitilde ] };

    key <AC01> { [            a,            A,          aacute,           Aacute ] };
    key <AC02> { [            r,            R,      dead_grave,       asciitilde ] };
    key <AC03> { [            s,            S,          ssharp,        0x1001e9e ] };
    key <AC04> { [            t,            T,      dead_acute, dead_doubleacute ] };
    key <AC05> { [            g,            G,     dead_ogonek,       asciitilde ] };
    key <AC06> { [            m,            M,     dead_macron,       asciitilde ] };
    key <AC07> { [            n,            N,          ntilde,           Ntilde ] };
    key <AC08> { [            e,            E,          eacute,           Eacute ] };
    key <AC09> { [            i,            I,          iacute,           Iacute ] };
    key <AC10> { [            o,            O,          oacute,           Oacute ] };
    key <AC11> { [   apostrophe,     quotedbl,          otilde,           Otilde ] };

    key <AB01> { [            z,            Z,              ae,               AE ] };
    key <AB02> { [            x,            X, dead_circumflex,       asciitilde ] };
    key <AB03> { [            c,            C,        ccedilla,         Ccedilla ] };
    key <AB04> { [            d,            D,  dead_diaeresis,       asciitilde ] };
    key <AB05> { [            v,            V,              oe,               OE ] };
    key <AB06> { [            k,            K,  dead_abovering,       asciitilde ] };
    key <AB07> { [            h,            H,      dead_caron,       asciitilde ] };
    key <AB08> { [        comma,         less,    dead_cedilla,       asciitilde ] };
    key <AB09> { [       period,      greater,   dead_abovedot,       asciitilde ] };
    key <AB10> { [        slash,     question,    questiondown,       asciitilde ] };

    key <CAPS> { [    BackSpace,    BackSpace,       BackSpace,        BackSpace ] };
    key <LSGT> { [        minus,   underscore,          endash,           emdash ] };
    key <SPCE> { [        space,        space,           space,     nobreakspace ] };

    include "level3(ralt_switch)"
};
"

# Write the layout content to the destination file
echo "$LAYOUT_CONTENT" | sudo tee "$LAYOUT_DEST" > /dev/null

# Backup the original evdev.xml if a backup doesn't already exist
if [ ! -f "${EVDEV_XML}.bak" ]; then
    sudo cp "$EVDEV_XML" "${EVDEV_XML}.bak"
fi

# Define the layout entry as a variable
LAYOUT_ENTRY="
  <layout>
    <configItem>
      <name>clmk-dh</name>
      <shortDescription>clmk-dh</shortDescription>
      <description>Colemak DH (Custom)</description>
      <languageList>
        <iso639Id>eng</iso639Id>
      </languageList>
    </configItem>
  </layout>"

# Use awk to insert the layout entry before the last </layoutList> tag
if ! grep -q "<name>clmk-dh</name>" "$EVDEV_XML"; then
    sudo awk -v layout_entry="$LAYOUT_ENTRY" '/<\/layoutList>/ { print layout_entry; found=1 } 1' "$EVDEV_XML" > evdev.xml.tmp && sudo mv evdev.xml.tmp "$EVDEV_XML"
fi

echo "Custom keyboard layout installed. You may need to log out and back in for changes to take effect."
