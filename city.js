angular.module('myApp')
    .controller('cityCtrl', function($rootScope, $scope){

        // var editor; // use a global for the submit and return data rendering in the examples

var url = 'http://11.239.171.218/admin/city/'

$(document).ready(function () {
    $.jgrid.styleUI.Bootstrap.base.rowTable = "table table-bordered table-striped";
    
    $("#jqGrid").jqGrid({
        url: url+"list",
        editurl: url+'edit',
        datatype: "json",
        prmNames : {search : "search",id:"id"},
        colModel: [
            {
                label: 'id',
                name: 'id',
                index:'id',
                formatter:'integer',
                // width: 75,
                key: true
            },
            {
                label : 'name',
                name: 'name',
                // width: 140,
                editable: true 
            },
            {
                label : 'namePy',
                name: 'namePy',
                // width: 140,
                editable: true 
            },
            {
                label : 'nameEn',
                name: 'nameEn',
                // width: 140,
                editable: true 
            },
            {
                label : 'adCode',
                name: 'adCode',
                // width: 140,
                editable: true 
            },
            {
                label: 'province',
                name: 'province',
                // width: 100,
                editable: true
            },
            {
                label: 'provinceCode',
                name: 'provinceCode',
                // width: 120,
                editable: true
            },
            {
                label: 'city',
                name: 'city',
                // width: 120,
                editable: true
            },
            {
                label: 'cityCode',
                name: 'cityCode',
                // width: 120,
                editable: true
            },
            {
                label: 'cityName',
                name: 'cityName',
                // width: 120,
                editable: true
            },
            {
                label: 'x',
                name: 'x',
                // width: 120,
                editable: true
            },
            {
                label: 'y',
                name: 'y',
                // width: 120,
                editable: true
            },
            {
                label: 'bottomleftx',
                name: 'bottomleftx',
                // width: 120,
                editable: true
            },
            {
                label: 'bottomlefty',
                name: 'bottomlefty',
                // width: 120,
                editable: true
            },
            {
                label: 'toperightx',
                name: 'toperightx',
                // width: 120,
                editable: true
            },
            {
                label: 'toperighty',
                name: 'toperighty',
                // width: 120,
                editable: true
            },
            {
                label: 'gridcode',
                name: 'gridcode',
                // width: 120,
                editable: true
            },
            {
                label: 'zoom',
                name: 'zoom',
                // width: 120,
                editable: true
            },
            {
                label: 'pixel',
                name: 'pixel',
                // width: 120,
                editable: true
            },
            {
                label: 'bottomleftpixel',
                name: 'bottomleftpixel',
                // width: 120,
                editable: true
            },
            {
                label: 'toperightpixel',
                name: 'toperightpixel',
                // width: 120,
                editable: true
            },
            {
                label: 'district',
                name: 'district',
                // width: 120,
                editable: true
            },
            {
                label: 'poiid',
                name: 'poiid',
                // width: 120,
                editable: true
            },
            {
                label: 'areaCode',
                name: 'areaCode',
                // width: 120,
                editable: true
            },
            {
                label: 'zipCode',
                name: 'zipCode',
                // width: 120,
                editable: true
            },
            {
                label: 'sequ',
                name: 'sequ',
                // width: 120,
                editable: true
            },
            {
                label: 'sName',
                name: 'sName',
                // width: 120,
                editable: true
            },
            {
                label: 'sNameEn',
                name: 'sNameEn',
                // width: 120,
                editable: true
            },
            {
                label: 'citycode',
                name: 'citycode',
                // width: 120,
                editable: true
            }

        ],
        viewrecords : true,
        sortname: 'id',
        sortorder: 'desc',
        loadonce: false,
        // width: 780,
        height: '100%',
        autowidth: true,
		rowList:[10,20,30,50],
        rowNum: 10,
        pager: "#jqGridPager",
        jsonReader : {  
            id:"id",
            root:"data",
            records:"totalNo",
            page:"pageNo",
            total:"totalPage"
        }  
    });

    $('#jqGrid').navGrid("#jqGridPager", {edit: true, add: true, del: true, refresh: true, view: true});
    $('#jqGrid').inlineNav('#jqGridPager',
        { 
            edit: true, 
            add: false, 
            del: true, 
            cancel: true,
            editParams: {
                keys: true,
            },
            addParams: {
                keys: true
            }
        });
});






})


