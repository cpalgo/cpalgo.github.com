function setActiveStyleSheet(title) {

    for (var index = 0, element; (element = document.getElementsByTagName("link")[index]); index++) {

        if(element.getAttribute("rel").indexOf("style") != -1 && 
           element.getAttribute("title")) {

            element.disabled = true;
            if(element.getAttribute("title") == title) {
                element.disabled = false;
            }
        }
    }
    if (title == "normal") {
        document.getElementById("gomb_bigger").style.display = "inline";
        document.getElementById("gomb_normal").style.display = "none";
    } else {
        document.getElementById("gomb_normal").style.display = "inline";
        document.getElementById("gomb_bigger").style.display = "none";
    }
}
  
function getActiveStyleSheet() {

    for (var index = 0, element; (element = document.getElementsByTagName("link")[index]); index++) {

        if(element.getAttribute("rel").indexOf("style") != -1 && 
           element.getAttribute("title") && !element.disabled) {
            return element.getAttribute("title");
        }
    }
    return null;
}
  
function getPreferredStyleSheet() {

    for(var index = 0, element; (element = document.getElementsByTagName("link")[index]); index++) {

        if(element.getAttribute("rel").indexOf("style") != -1 && 
           element.getAttribute("rel").indexOf("alt") == -1 && 
           element.getAttribute("title")) {
               return element.getAttribute("title");
        }
    }
    return null;
}
  
function createCookie(name, value, days) {

    if (days) {
        var date = new Date(), expires = "; expires=";
        date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
        expires += date.toGMTString();

    } else {
        expires = "";
    }
    document.cookie = name + "=" + value + expires + "; path=/";
}
  
function readCookie(name) {

    var nameEQ = name + "=";
    var tokens = document.cookie.split(';');

    for (var token in tokens) {

        while (token.charAt(0) == ' ') {
            token = token.substring(1, token.length);
        }
        if (token.indexOf(nameEQ) == 0) {
            return token.substring(nameEQ.length, token.length);
        }
    }
    return null;
}
  
window.onload = function() {

    var cookie = readCookie("style");
    var title = cookie? cookie: getPreferredStyleSheet();
    setActiveStyleSheet(title);
    document.getElementById('cim').innerHTML=cookie;
}
  
window.onunload = function() {

    var title = getActiveStyleSheet();
    createCookie("style", title, 365);
}