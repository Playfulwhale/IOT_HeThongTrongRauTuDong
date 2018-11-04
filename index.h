  const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>

<body>
  <div class="container">
    <div class="wrapper">
      <div class="title">
        <h1>HỆ THỐNG TRỒNG RAU TỰ ĐỘNG</h1>
        <div class="label-moitruong">MÔI TRƯỜNG</div>
      </div>

      <div class="moitruong">
        <div class="child">
          <div class="left nhietdo">
            <img src="cloud.svg">
            <div class="lbl">50<span> &deg; C</span></div>
            <div>Nhiệt độ</div>
          </div>
          <div class="left duongke"></div>
          <div class="left doam">
            <img src="drop.svg">
            <div class="lbl">20<span> %</span></div>
            <div>Độ ẩm</div>
          </div>
        </div>

      </div>
      <div class="den">
        <div class="label-dieukhien">ĐIỀU KHIỂN ĐÈN</div>
        <div class="gio giobat">
          <div class="label-gio-bat left">Giờ bật</div>
          <div class="combobox right">
            <select id="selectorid-gio-bat-den" class="combo" onchange="selectorGioBatDenOnChange()">
              <option value="0">Giờ</option>
            </select>
            <span>:</span>
            <select id="selectorid-phut-bat-den" class="combo" onchange="selectorGioBatDenOnChange()">
              <option value="0">Phút</option>
            </select>
          </div>
        </div>
        <div class="gio giotat">
          <div class="label-gio-tat left">Giờ tắt</div>
          <div class="combobox right">
            <select id="selectorid-gio-tat-den" class="combo" onchange="selectorGioTatDenOnChange()">
              <option value="0">Giờ</option>
            </select>
            <span>:</span>
            <select id="selectorid-phut-tat-den" class="combo" onchange="selectorGioTatDenOnChange()">
              <option value="0">Phút</option>
            </select>
          </div>
        </div>
        <div class="gio thongbao">
          <span>Đèn <span id="thoi-gian-bat-den"></span> <span id="thoi-gian-tat-den"></span>
          </span>
        </div>
        <div class="btn-chung">
          <input class="btn btn-on hienThi" id="btn-on" type="button" onclick="ledControl()"
           value="Bật đèn" />
          <div class="set-thoi-gian" id="set-thoi-gian-den-btn">
            <input class="btn btn-apply" type="button" value="Lưu" onclick="xuLyHenGioBatTat('selectorid-gio-bat-den','selectorid-phut-bat-den', 'selectorid-gio-tat-den', 'selectorid-phut-tat-den', 'btn-on', 'Bật đèn', 'Tắt đèn', 'btn-on', 'set-thoi-gian-den-btn',0)" />
            <input class="btn btn-cancel" type="button" value="Hủy" onclick="resetButton('selectorid-gio-bat-den', 'selectorid-gio-tat-den',0)" />
          </div>
        </div>
      </div>



      <div class="bom den">
        <div class="label-dieukhien">ĐIỀU KHIỂN BƠM</div>
        <div class="gio giobat">
          <div class="label-gio-bat left">Giờ bật</div>
          <div class="combobox right">
            <select id="selectorid-gio-bat-bom" class="combo" onchange="selectorGioBatBomOnChange()">
              <option value="0">Giờ</option>
            </select>
            <span>:</span>
            <select id="selectorid-phut-bat-bom" class="combo" onchange="selectorGioBatBomOnChange()">
              <option value="0">Phút</option>
            </select>
          </div>
        </div>
        <div class="gio giotat">
          <div class="label-gio-tat left">Giờ tắt</div>
          <div class="combobox right">
            <select id="selectorid-gio-tat-bom" class="combo" onchange="selectorGioTatBomOnChange()">
              <option value="0">Giờ</option>
            </select>
            <span>:</span>
            <select id="selectorid-phut-tat-bom" class="combo" onchange="selectorGioTatBomOnChange()">
              <option value="0">Phút</option>
            </select>
          </div>
        </div>
        <div class="gio thongbao">
          <span>Bơm <span id="thoi-gian-bat-bom"></span> <span id="thoi-gian-tat-bom"></span>
          </span>
        </div>
        <div class="btn-chung">
          <input class="btn btn-on hienThi" id="btn-bom" type="button" onclick="bomControl()"
           value="Bật bơm" />
          <div class="set-thoi-gian" id="set-thoi-gian-bom-btn">
            <input class="btn btn-apply" type="button" value="Lưu" onclick="xuLyHenGioBatTat('selectorid-gio-bat-bom','selectorid-phut-bat-bom', 'selectorid-gio-tat-bom', 'selectorid-phut-tat-bom', 'btn-bom', 'Bật bơm', 'Tắt bơm', 'btn-bom', 'set-thoi-gian-bom-btn',1)" />
            <input class="btn btn-cancel" type="button" value="Hủy" onclick="resetButton('selectorid-gio-bat-bom', 'selectorid-gio-tat-bom',1)" />
          </div>

        </div>
      </div>
    </div>
  </div>
<style>
  *{
  margin: 0;
  padding: 0;
}

.btn.btn-cancel:hover {
    /* background-color: #c9302c; */
    /* border-color: #ac2925; */
    /* background-color: #c9302c; */
    /* border-color: #ac2925; */
    background-color: #c9302c;
    border-color: #ac2925;
}

.btn.btn-cancel {
    left: 90px;
    /* top: 20px; */
    background-color: #c9302c;
    border-color: #ac2925;
    background-color: #d9534f;
    border-color: #d43f3a;
    padding-left: 15px;
    padding-right: 15px;
}

.btn-on:hover {
    color: #fff;
    background-color: #31b0d5;
    border-color: #269abc;
}

.btn-chung {
    position: relative;
    /* display: inline-block; */
}

.btn {
    position: absolute;
    /* display: inline-block; */
    padding: 6px 25px;
    margin-bottom: 0;
    font-size: 14px;
    font-weight: 400;
    line-height: 1.42857143;
    text-align: center;
    white-space: nowrap;
    vertical-align: middle;
    -ms-touch-action: manipulation;
    touch-action: manipulation;
    cursor: pointer;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
    user-select: none;
    background-image: none;
    border: 1px solid transparent;
    border-radius: 4px;
    color: #fff;
    background-color: #5bc0de;
    border-color: #46b8da;
    box-shadow: 2px 4px 8px 1px rgba(0,0,0,0.2);
    top: 0;
    left: 0;
    transform: translateY(-25%);
}

.combo {
    /* display: block; */
    width: 64px;
    height: 30px;
    padding: 0px 5px;
    font-size: 14px;
    line-height: 1.42857143;
    color: #555;
    background-color: #fff;
    background-image: none;
    border: 1px solid #ccc;
    border-radius: 4px;
    /* float: right; */
}

select#selector1 {
    /* width: 75%; */
}

.combo:focus {
    border-color: #66ccff;
    outline: 0;
    /* -webkit-box-shadow: inset 0 1px 1px rgba(0,0,0,.075), 0 0 8px rgba(102,175,233,.6); */
    box-shadow: inset 0 1px 1px rgba(0,0,0,.075), 0 0 8px rgba(102,175,233,.6);
}

.label-dieukhien {
    text-align: left;
    padding: 10px 0;
    border-bottom: 1px solid #d9d4d4;
}

.den {
    width: 100%;
    /* height: 200px; */
    background: white;
    padding: 10px 30px;
    box-sizing: border-box;
    margin-bottom: 30px;
    border-radius: 2px;
}

.child {
    width: 100%;
    height: 70%;
    position: relative;
    top: 50%;
    transform: translateY(-50%);
}

.lbl span {
    font-size: 18px;
    position: relative;
    bottom: 12px;
}

.nhietdo .lbl {
    /* font-size: 40px; */
    /* margin-bottom: 30px; */
    margin-right: 10%;
    /* font-weight: 500; */
}

.lbl {
    font-size: 40px;
    margin-bottom: 30px;
    /* margin-right: 10%; */
    font-weight: 500;
}

.left div:last-child {
    color: gray;
}

.title {
    position: relative;
    padding-bottom: 30px;
}

.label-moitruong {}

.label-moitruong {
    position: absolute;
    top: 100%;
    left: 25px;
    background: #33cccc;
    padding: 10px;
    border-radius: 3px;
    transform: translateY(-50%);
    color: white;
    box-shadow: 2px 4px 8px 1px rgba(0,0,0,0.2);
}

.moitruong {
    width: 100%;
    height: 100%;
    background: white;
    height: 160px;
    padding: 20px;
    box-sizing: border-box;
    margin-bottom: 30px;
    border-radius: 2px;
}

.left {width: 49.62%;float: left;/* line-height: 200px; */position: relative;/* top: 50%; *//* transform: translateY(-50%); */}

.gio .left {
    /* float: left; */
    text-align: left;
    width: 30%;
    /* padding: 20px 10px; */
}

.left.doam {
    right: 25%;
    transform: translateX(55%);
}

.left.nhietdo {
    transform: translateX(-55%);
    left: 25%;
}

.left img {
    width: 70px;
    position: absolute;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    z-index: -1;
}

.doam img {
    width: 50px;
    /* top: 25%; */
    /* left: 40%; */
}

.left.duongke {
    border-left: 1px solid #d9d4d4;
    width: 0;
    height: 100%;
    box-sizing: border-box;
}
.container{
  width: 40%;
  background: #66ccff;
  margin: auto;
  padding: 30px;
  /* height: 100%; */
  border-radius: 2px;
  box-sizing: border-box;
}
.wrapper {
    text-align: center;
    /* padding: 20px; */
    /* background: lightgreen; */
    width: 100%;
    height: 100%;
    /* border-radius: 2px; */
}

.btn-chung {
    /* width: 100%; */
}

.combobox.right {
    float: right;
    width: 70%;
    text-align: right;
    position: relative;
    top: 50%;
    transform: translateY(-50%);
}

.gio {
    height: 15px;
    padding: 20px 0px;
    padding-bottom: 5px;
}

.gio.thongbao {
    text-align: left;
    color: black;
    padding: 15px 0 24px 0;
}

.wrapper {}

body {
    font-family: Myriad Pro, sans-serif;
}

.wrapper h1 {
    font-size: 1.3rem;
    color: white;
    font-weight: 100;
    /* margin-bottom: 30px; */
}
.btn-on{
    display: none;
}
.set-thoi-gian{
    display: none;
}
.hienThi{
    display: block;
}
.lblColor{
    color: red;
}
@media only screen and (max-width: 600px) {
    .container {
        width: 100%;
        /* padding: 30px 0; */
    }
    /* .den, .moitruong{
        margin-bottom: 1px;
    } */
}
/*
@media only screen and (min-width: 600px) {

    .container {
        width: 70%;
    }
} */
/* 
@media only screen and (min-width: 768px) {
    .container {
        width: 100%;
    }
} */

@media only screen and (max-width: 768px) and (min-width:600px) {
    .container {
        width: 60%;
    }
}



/* @media only screen and (min-width: 900px) {
    .container {
        width: 40%;
    }
} */


@media only screen and (min-width: 1200px) {
    .container {
        width: 30%;
    }
}
</style>
  
  <script>
   function selectorGioBatDenOnChange() {
    hienThiBtnKhiClientSelect('selectorid-gio-bat-den', 'selectorid-gio-tat-den', 'set-thoi-gian-den-btn', 'btn-on');
    hienThiThoiThongBaoThoiGian('selectorid-gio-bat-den', 'selectorid-phut-bat-den', 'thoi-gian-bat-den', 'bật: ');
}
function selectorGioTatDenOnChange() {
    hienThiBtnKhiClientSelect('selectorid-gio-tat-den', 'selectorid-gio-bat-den', 'set-thoi-gian-den-btn', 'btn-on');
    hienThiThoiThongBaoThoiGian('selectorid-gio-tat-den', 'selectorid-phut-tat-den', 'thoi-gian-tat-den', ' &nbsp&nbsp tắt: ');
}

function selectorGioBatBomOnChange() {
    hienThiBtnKhiClientSelect('selectorid-gio-bat-bom', 'selectorid-gio-tat-bom', 'set-thoi-gian-bom-btn', 'btn-bom');
    hienThiThoiThongBaoThoiGian('selectorid-gio-bat-bom', 'selectorid-phut-bat-bom', 'thoi-gian-bat-bom', 'bật: ');
}
function selectorGioTatBomOnChange() {
    hienThiBtnKhiClientSelect('selectorid-gio-tat-bom', 'selectorid-gio-bat-bom', 'set-thoi-gian-bom-btn', 'btn-bom');
    hienThiThoiThongBaoThoiGian('selectorid-gio-tat-bom', 'selectorid-phut-tat-bom', 'thoi-gian-tat-bom', ' &nbsp&nbsp tắt: ');
}


// Load thời gian vào combobox
document.addEventListener("DOMContentLoaded", function () {
    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-den");
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-den");

    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-den");
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-den");

    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-bom");
    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-bom");

    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-bom");
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-bom");
});


function loadThoiGianHienThiLenCombobox(giaTriMin, giaTriMax, SelectorId) {
    var x = document.getElementById(SelectorId);
    for (var i = giaTriMin; i <= giaTriMax; i++) {
        var option = document.createElement("option");
        var value = i;
        if (i < 10) {
            value = "0" + i;
        }
        option.text = value;
        option.value = i;
        x.add(option);
    }

}


function kiemTraClientSelectCombobox(selelectId) {
    return (document.getElementById(selelectId).selectedIndex == 0) ? false : true;
}
// Ẩn hiện btn Lưu và Hủy, selelectIdCheck--sử dụng để xem 1 trong 2 giờ bật hoặc giờ tắt vẫn selected thì k remove class hiển thị
function hienThiBtnKhiClientSelect(selelectId, selelectIdCheck, btnMuonHienThiId, btnMuonAnId) {
    if (kiemTraClientSelectCombobox(selelectId) || kiemTraClientSelectCombobox(selelectIdCheck)) {
        document.getElementById(btnMuonHienThiId).classList.add('hienThi');
        document.getElementById(btnMuonAnId).classList.remove('hienThi');
    }
    else {
        document.getElementById(btnMuonHienThiId).classList.remove('hienThi');
        document.getElementById(btnMuonAnId).classList.add('hienThi');
    }
}

// hiển thị ở label thông báo bật tắt lúc nào
function hienThiThoiThongBaoThoiGian(selectorID_Gio, selectorID_Phut, lableChangeSpanID, lblHienThi) {
    var idGio = document.getElementById(selectorID_Gio);
    var index_Gio = idGio.selectedIndex;
    var value_Gio = idGio.options[index_Gio].text;
    if (index_Gio != 0) {
        var idPhut = document.getElementById(selectorID_Phut);
        if (selectorID_Phut == '') {
            document.getElementById(lableChangeSpanID).innerHTML = value_Gio;
            //startTimer(lableChangeSpanID, 100);
        }
        else {
            var index_Phut = idPhut.selectedIndex;
            var value_Phut = idPhut.options[index_Phut].text;
            if (index_Phut == 0) { value_Phut = "00"; }
            document.getElementById(lableChangeSpanID).innerHTML = lblHienThi + "<span class='lblColor'>" + value_Gio + ":" + value_Phut + "</span>";
        }
    }
    else {
        document.getElementById(lableChangeSpanID).innerHTML = " ";
        document.getElementById(selectorID_Phut).selectedIndex = 0;
    }
}

// Nếu value = 0 => nút của đèn sẽ reset và ngược lại
function resetButton(selectorID_GioBat, selectorID_GioTat, value) {
    document.getElementById(selectorID_GioBat).selectedIndex = 0;
    document.getElementById(selectorID_GioTat).selectedIndex = 0;
    if (value == 0) {

        selectorGioBatDenOnChange();
        selectorGioTatDenOnChange()
    }
    else {
        selectorGioBatBomOnChange();
        selectorGioTatBomOnChange();
    }

}

function onLyBtnReset(btnMuonHienThiId, btnMuonAnId) {
    document.getElementById(btnMuonHienThiId).classList.add('hienThi');
    document.getElementById(btnMuonAnId).classList.remove('hienThi');
}



// Đổi giờ sang giây
function doiGioPhutSangGiay(gio, phut) {
    var d = new Date();
    var h = d.getHours();
    var m = d.getMinutes();
    var s = d.getSeconds();
    gio -= h;
    if (m > phut) {
        phut = phut + 60 - m;
        gio--;
    }
    else {
        phut -= m;
    }
    var giay = (gio * 3600) + (phut * 60) - s;
    if (giay < 0)
        giay = 0;
    return giay;
}

//selectorBtnId: btn hiển thị trạng thái đang on hay off
//onStatus: chuỗi hiển thị ở btn đó
function xuLyHenGioBatTat(selectorGioBat, selectorPhutBat, selectorGioTat, selectorPhutTat, selectorBtnId, onStatus, offStatus, btnMuonHienThiId, btnMuonAnId, value) {
    var thoiGianBatDen_Gio, thoiGianBatDen_Phut;
    var thoiGianTatDen_Gio, thoiGianTatDen_Phut;
    thoiGianBatDen_Gio = document.getElementById(selectorGioBat).value;
    thoiGianBatDen_Phut = document.getElementById(selectorPhutBat).value;
    thoiGianTatDen_Gio = document.getElementById(selectorGioTat).value;
    thoiGianTatDen_Phut = document.getElementById(selectorPhutTat).value;

    onLyBtnReset(btnMuonHienThiId, btnMuonAnId);
    if (kiemTraClientSelectCombobox(selectorGioBat)) {
        var thoigianbatden = parseInt(doiGioPhutSangGiay(thoiGianBatDen_Gio, thoiGianBatDen_Phut)) * 1000;
        if (kiemTraClientSelectCombobox(selectorGioTat)) { // Có cả thời gian bật và thời gian tắt
            var thoigiantatden = parseInt(doiGioPhutSangGiay(thoiGianTatDen_Gio, thoiGianTatDen_Phut)) * 1000;
            setTimeout(function () {
                if(value == 0)
                    {
                      ledControl1(1);
                    }
                    else
                    {
                      bomControl1(1)  
                    }
                setTimeout(function () {
                    if(value == 0)
                    {
                      ledControl1(0);
                    }
                    else
                    {
                      bomControl1(0)  
                    }
                    resetButton(selectorGioBat, selectorGioTat, value);
                }, thoigiantatden - thoigianbatden);
            }, thoigianbatden);
        }
        else // Chỉ có thời gian bật đèn
        {
            setTimeout(function () {
                if(value == 0)
                    {
                      ledControl1(1);
                    }
                    else
                    {
                      bomControl1(1)  
                    }
                resetButton(selectorGioBat, selectorGioTat, value);
            }, thoigianbatden);
        }
    }
    else // Chỉ có thời gian tắt đèn
    {
        var thoigiantatden = parseInt(doiGioPhutSangGiay(thoiGianTatDen_Gio, thoiGianTatDen_Phut)) * 1000;
        loadThoiGianThongBao(selectorGioTat, selectorPhutTat, 'lableGioTatDen', 'lableThongbaoTatDen');
        setTimeout(function () {
            if(value == 0)
                    {
                      ledControl1(0);
                    }
                    else
                    {
                      bomControl1(0)  
                    }
            resetButton(selectorGioBat, selectorGioTat, value);
        }, thoigiantatden);
    }
}





  </script>
  
  <script>
    var xhttp = new XMLHttpRequest();
    function getData() {
      xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("nhietdo").innerHTML =
          this.responseText; // Nhan ket qua tu server
      }
  };
  xhttp.open("GET", "temp", true); // Tao yeu cau tu client
  xhttp.send(); // Gui yeu cau cua client len Server
}
function getDoAm() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("doam").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "humi", true);
  xhttp.send();
}




function ledControl1(led) {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-on").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "led1?stus="+led, true);
  xhttp.send();
}
function ledControl() {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-on").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "led", true);
  xhttp.send();
}
function bomControl1(bom) {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-bom").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "bom1?stus="+bom, true);
  xhttp.send();
}

function bomControl() {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-bom").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "bom", true);
  xhttp.send();
}

  // Hàm thực hiện gửi yêu cầu của client cứ 1s gửi 1 lần
  setInterval(function() {
    getData();
    getDoAm();
  }, 2000);
  
</script>


</body></html>
)=====";
