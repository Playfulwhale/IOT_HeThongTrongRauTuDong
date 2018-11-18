  const char MAIN_page[] PROGMEM = R"=====(
  <html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>

<body>
  <div class="container">
    <div class="wrapper">
      <div class="tren">
        <div class="title">
          <h1>HỆ THỐNG TRỒNG RAU TỰ ĐỘNG</h1>
        </div>
        <div class="duongke">
          <div></div>
        </div>
        <div class="moitruong">
          <div class="left nhietdo">
            <div class="lbl" id="nhietdo">50<span> ° C</span></div>
            <div>Nhiệt độ</div>
          </div>
          <div class="left doam">
            <div class="lbl" id="doam">20<span> %</span></div>
            <div>Độ ẩm</div>
          </div>
          <div class="clear"></div>
        </div>
        <div class="control">
          <input type="button" name="" class="batden btn" value="Bật đèn" id="btn-den" onclick="ledControl()">
          <input type="button" class="batbom btn" value="Bật bơm" id="btn-bom" onclick="bomControl()">
          <div class="clear"></div>
        </div>
      </div>
      <div class="box">
        <div class="hengio hienthitab" id="tab-den">
          <div class="den"> 
            <div class="label-dieukhien active left" onclick="hienThiTab('tab-den', 'tab-bom')">ĐIỀU KHIỂN ĐÈN</div>
            <div class="kedoc left">
              <div class="doc"></div>
            </div>
            <div class="label-dieukhien left right" onclick="hienThiTab('tab-bom','tab-den')">ĐIỀU KHIỂN BƠM</div>
            <div class="gio giobat">
              <div class="label-gio-bat left">Giờ bật</div>
              <div class="combobox left">
                <select id="selectorid-gio-bat-den" class="combo" onchange="selectorGioBatDenOnChange()">
                  <option value="0">Giờ</option>
                </select>
                <span>:</span>
                <select id="selectorid-phut-bat-den" class="combo" onchange="selectorGioBatDenOnChange()">
                  <option value="0">Phút</option>
                </select>
              </div>
              <div class="clear"></div>
            </div>
            <div class="gio giotat">
              <div class="label-gio-tat left">Giờ tắt</div>
              <div class="combobox left">
                <select id="selectorid-gio-tat-den" class="combo" onchange="selectorGioTatDenOnChange()">
                  <option value="0">Giờ</option>
                </select>
                <span>:</span>
                <select id="selectorid-phut-tat-den" class="combo" onchange="selectorGioTatDenOnChange()">
                  <option value="0">Phút</option>
                </select>
              </div>
              <div class="clear"></div>
            </div>
            <div class="gio thongbao gioden">
              <span>Đèn <span id="thoi-gian-bat-den"></span> <span id="thoi-gian-tat-den"></span>
              </span>
            </div>
            <div class="gio thongbao giobom">
              <span>Bơm <span id="thoi-gian-bat-bom-den"></span> <span id="thoi-gian-tat-bom-den"></span>
              </span>
            </div>
            <div class="btn-chung">
              <div class="set-thoi-gian" id="set-thoi-gian-den-btn">
                <input id="luu-den" class="btn btn-apply btn-hengio" type="button" value="Lưu" onclick="xuLyHenGioBatTat('selectorid-gio-bat-den','selectorid-phut-bat-den', 'selectorid-gio-tat-den', 'selectorid-phut-tat-den', 0)">
                <input class="btn btn-cancel btn-hengio" type="button" value="Hủy" onclick="xuLyCancel(0)">
              </div>
            </div>
          </div>



        </div>

        <!-- ================= Bơm ==================== -->
        <div class="hengio box-bom" id="tab-bom">
          <div class="den">
            <div class="label-dieukhien left" onclick="hienThiTab('tab-den', 'tab-bom')">ĐIỀU KHIỂN ĐÈN</div>
            <div class="kedoc left">
              <div class="doc"></div>
            </div>
            <div class="label-dieukhien active left right" onclick="hienThiTab('tab-bom','tab-den')">ĐIỀU KHIỂN BƠM</div>
            <div class="gio giobat">
              <div class="label-gio-bat left">Giờ bật</div>
              <div class="combobox left">
                <select id="selectorid-gio-bat-bom" class="combo" onchange="selectorGioBatBomOnChange()">
                  <option value="0">Giờ</option>
                </select>
                <span>:</span>
                <select id="selectorid-phut-bat-bom" class="combo" onchange="selectorGioBatBomOnChange()">
                  <option value="0">Phút</option>
                </select>
              </div>
              <div class="clear"></div>
            </div>
            <div class="gio giotat">
              <div class="label-gio-tat left">Giờ tắt</div>
              <div class="combobox left">
                <select id="selectorid-gio-tat-bom" class="combo" onchange="selectorGioTatBomOnChange()">
                  <option value="0">Giờ</option>
                </select>
                <span>:</span>
                <select id="selectorid-phut-tat-bom" class="combo" onchange="selectorGioTatBomOnChange()">
                  <option value="0">Phút</option>
                </select>
              </div>
              <div class="clear"></div>
            </div>
            <div class="gio thongbao gioden">
              <span>Đèn <span id="thoi-gian-bat-den-bom"></span> <span id="thoi-gian-tat-den-bom"></span>
              </span>
            </div>
            <div class="gio thongbao giobom">
              <span>Bơm <span id="thoi-gian-bat-bom"></span> <span id="thoi-gian-tat-bom"></span>
              </span>
            </div>
            <div class="btn-chung">
              <div class="set-thoi-gian" id="set-thoi-gian-bom-btn">
                <input id="luu-bom" class="btn btn-apply btn-hengio" type="button" value="Lưu" onclick="xuLyHenGioBatTat('selectorid-gio-bat-bom','selectorid-phut-bat-bom', 'selectorid-gio-tat-bom', 'selectorid-phut-tat-bom', 1)">
                <input class="btn btn-cancel btn-hengio" type="button" value="Hủy" onclick="xuLyCancel(1)">
              </div>
            </div>
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

.box {
    position: relative;
    width: 100%;
}

.box-bom {
    width: 100%;
    top: 0;
    left: 0;
    padding: 15px;
    box-sizing: border-box;
    position: relative;
}

.box-hengio {
    position: relative;
    width: 100%;
}

.doc {
    height: 100%;
    width: 1px;
    background: #aaa3a3;
    margin: auto;
}

.btn-chung {
    text-align: center;
}

.combo {
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
}

.combo:focus {
    border-color: #66ccff;
    outline: 0;
    box-shadow: inset 0 1px 1px rgba(0,0,0,.075), 0 0 8px rgba(102,175,233,.6);
}

.tren {
    padding: 0 15px;
}

.gio {
    padding: 0 20px;
    line-height: 24px;
}

.gio.giotat {
    line-height: 40px;
    margin-bottom: 10px;
}

.gio.giobat {
    line-height: 40px;
}

.giobom {
    margin-bottom: 10px;
}

.gio.thongbao.gioden {}

.label-dieukhien.active {
    background: #66ccff;
    color: white;
}

.den {}

.label-dieukhien {
    height: 40px;
    line-height: 40px;
    border-radius: 50px;
    background: white;
    box-sizing: border-box;
    border: 1px solid #66ccff;
    text-align: center;
    outline-width: 0px;
    width: 45%;
    cursor: pointer;
    margin-bottom: 20px;
    font-size: 90%;
    width: 44% !important;
}

.hengio {
    border: 1px solid #66ccff;
    padding: 15px;
    display: none;
}

.hienthitab {
    display: block;
}

.hengio.bom {
    position: absolute;
    top: 0;
    width: 100%;
    box-sizing: border-box;
}

.clear {
    clear: both;
}

.control {
    width: 100%;
    height: 40px;
    margin-bottom: 20px;
}

h1 {
    font-weight: 100;
}

.moitruong span {
    font-size: 20px;
    position: relative;
    bottom: 12px;
}

.moitruong .lbl {
    font-size: 50px;
    color: #66ccff;
}

.left {
    float: left;
    width: 50%;
}

.kedoc {
    width: 10%;
    height: 40px;
    margin: auto;
    position: relative;
}

.label-dieukhien.left.right {
    float: right;
}

.gio .left {
    width: 30%;
}

.combobox.left {
    text-align: right;
    width: 70%;
}
.btn {
    height: 40px;
    line-height: 40px;
    border-radius: 50px;
    background: white;
    box-sizing: border-box;
    border: 1px solid #66ccff;
    text-align: center;
    outline-width: 0px;
    width: 45%;
    cursor: pointer;
}

.btn-hengio {
    width: 100px;
    margin: 0 12px;
}
input.btn:disabled {
    background: #ede9e9;
}
input.btn:disabled:hover {
    background: #ede9e9;
    color: grey;
    cursor: unset;
}
input.batbom.btn {
    float: right;
}

.batden.left {}

input.control .left:focus {
    border-radius: 0;
}


.btn:hover {
    color: #fff;
    background-color: #66ccff;
}
.btn:active:focus {
    color: #fff;
    background-color: #36b6dc;
    border-color: #66ccff;
}
.batbom.left {
    float: right;
}

.moitruong .left {
    text-align: center;
    padding: 20px 0;
    padding-top: 10px;
}

.moitruong {
    width: 100%;
}

.duongke div {
    width: 13%;
    background: #66ccff;
    height: 100%;
    border-radius: 0 4px 4px 0;
}

.duongke {
    width: 100%;
    background: #ede9e9;
    height: 5px;
}

.title {
    font-size: 0.7rem;
    text-align: center;
    padding: 0 0 20px 0;
}

.wrapper {
    width: 100%;
}

.container {
    width: 40%;
    margin: auto;
    background: white;
    padding: 15px;
    box-sizing: border-box;
    border: 1px solid blue;
}


body {
    font-family: Myriad Pro, sans-serif;
}
@media only screen and (min-width: 1200px) {
    .container {
        width: 30%;
    }
}
@media only screen and (max-width: 768px) and (min-width:600px) {
    .container {
        width: 60%;
    }
}
@media only screen and (max-width: 600px) {
    .container {
        width: 100%;
    }
    .label-dieukhien{font-size: 80%;}
    .combo{
        width: 60px;
    padding: 0px 1px;
    }
}
@media only screen and (max-width: 375px) {
    .container {
        width: 100%;
    }
    .label-dieukhien{font-size: 80%;}
    .combo{
        width: 63px;
        padding: 0px 1px;
        font-size: 13px;
    }
}


</style>

<script>
  

// Thay đổi trạng thái bật tắt của bơm và đèn
function ledChange(selectorId, onStatus, offStatus) {
    var tinhieu = document.getElementById(selectorId).value; // Lấy giá trị của selector
    if (tinhieu == onStatus) {
        document.getElementById(selectorId).value = offStatus;
    }
    else {
        document.getElementById(selectorId).value = onStatus;
    }
}

function ledChangeDetail(tinhieu, selectorId, onStatus, offStatus) {
    if (tinhieu == 1) {
        document.getElementById(selectorId).value = offStatus;
    }
    else {
        document.getElementById(selectorId).value = onStatus;
    }
}

function loadThoiGianHienThiLenCombobox(giaTriMin, giaTriMax, SelectorId, giaTriSetThoiGian) {
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

    // Tìm xem thời gian đã set thời gian hay chưa, nếu có thì select đúng chỗ đó
    if(giaTriSetThoiGian >= 0)
    {
      var danhSachOption = document.querySelectorAll("#"+ SelectorId + " option");
      console.log(danhSachOption);
      for (var i = 1; i < danhSachOption.length ; i++) {
        var giatri = danhSachOption[i].value;
        if(giaTriSetThoiGian == giatri)
        {
          x.selectedIndex = i;
          break;
        }
      }
    }
    else {
        var danhSachOption = document.querySelectorAll("#" + SelectorId + " option");
        x.selectedIndex = 0;
    }

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
var setGioBatDen = setGioTatDen = setGioBatBom = setGioTatBom = -1;
var setPhutBatDen = setPhutTatDen = setPhutBatBom = setPhutTatBom = -1;
var checkComboxBatDen = checkComboxTatDen = 0;
var checkComboxBatBom = checkComboxTatBom = 0;
function loadToanBoCombobox() {
    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-den", setGioBatDen);
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-den", setPhutBatDen);

    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-den", setGioTatDen);
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-den", setPhutTatDen);

    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-bom", setPhutBatBom );
    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-bom", setGioBatBom);

    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-bom", setGioTatBom);
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-bom", setPhutTatBom);
}

function loadComboboxBatDen() {
  loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-den", setGioBatDen);
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-den", setPhutBatDen);
}
function loadComboboxTatDen() {
    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-den", setGioTatDen);
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-den", setPhutTatDen);
}

function loadComboboxBatBom() {
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-bom", setPhutBatBom );
    loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-bom", setGioBatBom);
}
function loadComboboxTatBom() {
   loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-bom", setGioTatBom);
    loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-bom", setPhutTatBom);
}

function loadComboboxDen() {
   loadComboboxBatDen();
   loadComboboxTatDen();
}
function loadComboboxBom() {
   loadComboboxBatBom();
   loadComboboxTatBom();
    
}
//function getThoiGianHenGio() {
//  
//  setTimeout(function(){
//    
//    ledCheck();
//  }, 2000);
//  setTimeout(function(){
//   
//  }, 2000);
//  
//}

// Load thời gian vào combobox
document.addEventListener("DOMContentLoaded", function () {
    setTimeout(function(){
      getGioBatDen();
        setTimeout(function(){
          getPhutBatDen();
            setTimeout(function(){
              getGioTatDen();
                setTimeout(function(){
                    getPhutTatDen(); 
                      setTimeout(function(){
                        ledCheck();
                      }, 400);
                        setTimeout(function(){
                          loadComboboxDen();
                          console.log("Giờ bật đèn: " + setGioBatDen);
                          console.log("setPhutBatDen: " + setPhutBatDen);
                          console.log("setGioTatDen: " + setGioTatDen);
                          console.log("setPhutTatDen: " + setPhutTatDen);
                          selectorGioBatDenOnChange();
                          selectorGioTatDenOnChange();
                          thayDoiDisableOfBtn(0, 0);
                      }, 500);
                }, 200);
            }, 200);            
        }, 200);
    }, 200);
    
//                    -------- Bơm ----
  setTimeout(function(){
        getGioBatBom();
         setTimeout(function(){
            getPhutBatBom();
             setTimeout(function(){
                getGioTatBom();
                 setTimeout(function(){
                    getPhutTatBom();
                    setTimeout(function(){
                       bomCheck();
                    }, 400);
                      setTimeout(function(){
                            loadComboboxBom();
                            console.log("setGioBatBom: " + setGioBatBom);
                            console.log("setPhutBatBom: " + setPhutBatBom);
                            console.log("setGioTatBom: " + setGioTatBom);
                            console.log("setPhutTatBom: " + setPhutTatBom);
                             selectorGioBatBomOnChange();
                             selectorGioTatBomOnChange();
                             thayDoiDisableOfBtn(1, 0);
                      }, 500);
                  }, 200);
             }, 200);
         }, 200);
  }, 500);
   

});


// value: 0 -> đèn, 1-> bơm
// hienthi: 0 -> disabled, 1-> bỏ disabled
function thayDoiDisableOfBtn(value, hienthiDisable) {
    if (hienthiDisable == 0) {
        if (value == 0) {
            document.getElementById("luu-den").disabled = true;
        }
        else if (value == 1) {
            document.getElementById("luu-bom").disabled = true;
        }
    }
    else {
        if (value == 0) {
            document.getElementById("luu-den").disabled = false;
        }
        else if (value == 1) {
            document.getElementById("luu-bom").disabled = false;
        }
    }
}

function selectorGioBatDenOnChange() {
    
    //hienThiBtnKhiClientSelect('selectorid-gio-bat-den', 'selectorid-gio-tat-den', 'set-thoi-gian-den-btn', 'btn-on');
    hienThiThoiThongBaoThoiGian('selectorid-gio-bat-den', 'selectorid-phut-bat-den', 'thoi-gian-bat-den', 'bật: ');
    hienThiThoiThongBaoThoiGian('selectorid-gio-bat-den', 'selectorid-phut-bat-den', 'thoi-gian-bat-den-bom', 'bật: ');
    thayDoiDisableOfBtn(0, 1);
}
function selectorGioTatDenOnChange() {
   
    //hienThiBtnKhiClientSelect('selectorid-gio-tat-den', 'selectorid-gio-bat-den', 'set-thoi-gian-den-btn', 'btn-on');
    hienThiThoiThongBaoThoiGian('selectorid-gio-tat-den', 'selectorid-phut-tat-den', 'thoi-gian-tat-den', ' &nbsp&nbsp tắt: ');
    hienThiThoiThongBaoThoiGian('selectorid-gio-tat-den', 'selectorid-phut-tat-den', 'thoi-gian-tat-den-bom', ' &nbsp&nbsp tắt: ');
     thayDoiDisableOfBtn(0, 1);
}

function selectorGioBatBomOnChange() {
    
    //hienThiBtnKhiClientSelect('selectorid-gio-bat-bom', 'selectorid-gio-tat-bom', 'set-thoi-gian-bom-btn', 'btn-bom');
    hienThiThoiThongBaoThoiGian('selectorid-gio-bat-bom', 'selectorid-phut-bat-bom', 'thoi-gian-bat-bom', 'bật: ');
    hienThiThoiThongBaoThoiGian('selectorid-gio-bat-bom', 'selectorid-phut-bat-bom', 'thoi-gian-bat-bom-den', 'bật: ');
    thayDoiDisableOfBtn(1, 1);
}
function selectorGioTatBomOnChange() {
   
    //hienThiBtnKhiClientSelect('selectorid-gio-tat-bom', 'selectorid-gio-bat-bom', 'set-thoi-gian-bom-btn', 'btn-bom');
    hienThiThoiThongBaoThoiGian('selectorid-gio-tat-bom', 'selectorid-phut-tat-bom', 'thoi-gian-tat-bom', ' &nbsp&nbsp tắt: ');
    hienThiThoiThongBaoThoiGian('selectorid-gio-tat-bom', 'selectorid-phut-tat-bom', 'thoi-gian-tat-bom-den', ' &nbsp&nbsp tắt: ');
     thayDoiDisableOfBtn(1, 1);
}



function hienThiTab(idShowTab, idHideTab) {
    document.getElementById(idShowTab).classList.add("hienthitab");
    document.getElementById(idHideTab).classList.remove("hienthitab");
}
function kiemTraClientSelectCombobox(selelectId) {
    return (document.getElementById(selelectId).selectedIndex == 0) ? false : true;
}

function xuLyCancel(value) {
    setGioBatDen = setGioTatDen = setGioBatBom = setGioTatBom = -1;
    setPhutBatDen = setPhutTatDen = setPhutBatBom = setPhutTatBom = -1;

    if (value == 0) {
        
        loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-den", setGioBatDen);
        loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-den", setPhutBatDen);

        loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-den", setGioTatDen);
        loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-den", setPhutTatDen);
        selectorGioBatDenOnChange();
        selectorGioTatDenOnChange();
        thayDoiDisableOfBtn(0, 0);
        ledControl1(1, setGioBatDen, setPhutBatDen);
        setTimeout(function(){ 
           ledControl1(0, setGioTatDen, setPhutTatDen);
          }, 1000);
       
    }
    else if (value == 1) {
        
        loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-bat-bom", setGioBatBom);
        loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-bat-bom", setPhutBatBom);

        loadThoiGianHienThiLenCombobox(0, 23, "selectorid-gio-tat-bom", setGioTatBom);
        loadThoiGianHienThiLenCombobox(0, 59, "selectorid-phut-tat-bom", setPhutTatBom);
        selectorGioBatBomOnChange();
        selectorGioTatBomOnChange();
        thayDoiDisableOfBtn(0, 1);
        bomControl1(1, setGioBatBom, setPhutBatBom);
        setTimeout(function(){ 
          bomControl1(0, setGioTatBom, setPhutTatBom); 
        }, 1000);
        
    }
}

//selectorBtnId: btn hiển thị trạng thái đang on hay off
//onStatus: chuỗi hiển thị ở btn đó
function xuLyHenGioBatTat(selectorGioBat, selectorPhutBat, selectorGioTat, selectorPhutTat, value) {

    var thoiGianBat_Gio, thoiGianBat_Phut;
    var thoiGianTat_Gio, thoiGianTat_Phut;
    thoiGianBat_Gio = document.getElementById(selectorGioBat).value;
    thoiGianBat_Phut = document.getElementById(selectorPhutBat).value;
    thoiGianTat_Gio = document.getElementById(selectorGioTat).value;
    thoiGianTat_Phut = document.getElementById(selectorPhutTat).value;

    // set lai thoi gian khi click btn Luu
    if (value == 0) {
        checkComboxBatDen = checkComboxTatDen = 0;
        setGioBatDen = thoiGianBat_Gio;
        setPhutBatDen = thoiGianBat_Phut;
        setGioTatDen = thoiGianTat_Gio;
        setPhutTatDen = thoiGianTat_Phut;
    }
    else if (value == 1) {
      checkComboxBatBom = checkComboxTatBom = 0;
        setGioBatBom = thoiGianBat_Gio;
        setPhutBatBom = thoiGianBat_Phut;
        setGioTatBom = thoiGianTat_Gio;
        setPhutTatBom = thoiGianTat_Phut;
    }
    
    thayDoiDisableOfBtn(value, 0);
    if (kiemTraClientSelectCombobox(selectorGioBat)) {
        if (kiemTraClientSelectCombobox(selectorGioTat)) { // Có cả thời gian bật và thời gian tắt
            if (value == 0) {
              
                ledControl1(1, thoiGianBat_Gio, thoiGianBat_Phut);
                setTimeout(function(){ ledControl1(0, thoiGianTat_Gio, thoiGianTat_Phut); }, 1000);
                
            }
            else if (value == 1) {
                bomControl1(1, thoiGianBat_Gio, thoiGianBat_Phut);
                setTimeout(function(){ bomControl1(0, thoiGianTat_Gio, thoiGianTat_Phut); }, 1000);
                
            }
        }
        else // Chỉ có thời gian bật đèn
        {
            if (value == 0) {
                ledControl1(1, thoiGianBat_Gio, thoiGianBat_Phut);
            }
            else if (value == 1) {
                bomControl1(1, thoiGianBat_Gio, thoiGianBat_Phut);
            }
        }
    }
    else // Chỉ có thời gian tắt đèn
    {
        if (value == 0) {
            ledControl1(0, thoiGianTat_Gio, thoiGianTat_Phut);
        }
        else if (value == 1) {
            bomControl1(0, thoiGianTat_Gio, thoiGianTat_Phut);
        }
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



function ledCheck() {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-den").value =
      this.responseText;
      console.log("ledStatus: " + this.responseText);
    }
  };
  xhttp.open("GET", "ledCheckStatus", true);
  xhttp.send();
}

function bomCheck() {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-bom").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "bomCheckStatus", true);
  xhttp.send();
}


function getGioBatDen() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setGioBatDen = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "giobatden", true);
  xhttp.send();
}
function getPhutBatDen() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setPhutBatDen = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "phutbatden", true);
  xhttp.send();
}

function getGioTatDen() {
  console.log("OK có nhảy giờ tắt");
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setGioTatDen = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "giotatden", true);
  xhttp.send();
}

function getPhutTatDen() {
  console.log("OK có nhảy phút tắt");
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setPhutTatDen = parseInt(this.responseText);
      console.log("Phút tắt đèn nè: " + parseInt(this.responseText));
    }
  };
  xhttp.open("GET", "phuttatden", true);
  xhttp.send();
}


function getGioBatBom() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setGioBatBom = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "giobatbom", true);
  xhttp.send();
}
function getPhutBatBom() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setPhutBatBom = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "phutbatbom", true);
  xhttp.send();
}

function getGioTatBom() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setGioTatBom = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "giotatbom", true);
  xhttp.send();
}
function getPhutTatBom() {
  xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      setPhutTatBom = parseInt(this.responseText);
    }
  };
  xhttp.open("GET", "phuttatbom", true);
  xhttp.send();
}

function ledControl1(led, gio, phut) {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-den").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "led1?stus="+led+"&gio="+gio+"&phut="+phut, true);
  xhttp.send();
}
function ledControl() {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-den").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "led", true);
  xhttp.send();
}
function bomControl1(bom, gio, phut) {
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("btn-bom").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "bom1?stus="+bom+"&gio="+gio+"&phut="+phut, true);
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


setInterval(function () {
    var d = new Date();
    var h = d.getHours();
    var m = d.getMinutes();
    if (((m == setPhutBatDen) && (h == setGioBatDen))) {
      if(checkComboxBatDen == 0)
      {
        console.log("Da vo day");
        checkComboxBatDen++;
        ledCheck();
        setGioBatDen =setPhutBatDen  = -1;
        loadComboboxBatDen();
        selectorGioBatDenOnChange();
      }
       
    }
    if(((m == setPhutTatDen) && (h == setGioTatDen)))
    {
      if(checkComboxTatDen == 0)
      {
          checkComboxTatDen++;
          ledCheck();
          setGioTatDen = setPhutTatDen = -1;
          loadComboboxTatDen();
          selectorGioTatDenOnChange();
      }
      
    }
    if (((m == setPhutBatBom)&& (h == setGioBatBom))) {
      if(checkComboxBatBom == 0)
      {
        checkComboxBatBom++;
        bomCheck();
        setGioBatBom =setPhutBatBom  = -1;
        loadComboboxBatBom();
        selectorGioBatBomOnChange();
      }
        
    }
    if(((m == setPhutTatBom) && (h == setGioTatBom)))
    {
      if(checkComboxTatBom == 0)
      {
        checkComboxTatBom++;
        bomCheck();
        setGioTatBom = setPhutTatBom = -1;
        loadComboboxTatBom();
        selectorGioTatBomOnChange();
      }
        
    }
}, 1000);

  // Hàm thực hiện gửi yêu cầu của client cứ 1s gửi 1 lần
//  setInterval(function() {
//    getData();
//    getDoAm();
//  }, 2000);
//  
</script>


</body></html>
)=====";
