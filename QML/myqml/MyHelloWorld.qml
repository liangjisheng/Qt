import QtQuick 2.0

Rectangle {
    width: 100
    height: 62
    // 在Rectangle自定义属性mArea,alias表明mArea是mouseArea的别名
    // 这样在MyHelloWorld.xml文件外就可以通过mArea来操作MouseArea对象了
    property alias mArea: mouseArea
    Text {
        text: "hello world"
        // 文本默认在左上角显示，现在居中显示
        anchors.centerIn: parent
    }
    // 添加一个MouseArea子对象，它是一个不可见对象，通过该对象可以实现鼠标互动
    MouseArea {
        // fill填充，将鼠标区域覆盖到整个Rectangle窗口
        // anchors.fill: parent
        id: mouseArea   // 设置id，这样就可以在Rectangle中通过mouseRrea访问MouseArea对象
        onClicked: {
            Qt.quit()
        }
    }
}

/*Item {

}*/
