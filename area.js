angular.module('myApp')
    .controller('areaCtrl', function($rootScope, $scope){

        // var editor; // use a global for the submit and return data rendering in the examples

var url = 'http://11.239.171.218/admin/area/'

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
                label : 'area_poi_id',
                name: 'area_poi_id',
                // width: 140,
                editable: true 
            },
            {
                label : 'area_poi_name',
                name: 'area_poi_name',
                // width: 140,
                editable: true 
            },
            {
                label : 'area_poi_type',
                name: 'area_poi_type',
                // width: 140,
                editable: true 
            },
            {
                label : 'area_center_x',
                name: 'area_center_x',
                // width: 140,
                editable: true 
            },
            {
                label: 'area_center_y',
                name: 'area_center_y',
                // width: 100,
                editable: true
            },
            {
                label: 'area_size',
                name: 'area_size',
                // width: 120,
                editable: true
            },
            {
                label: 'area_adcode',
                name: 'area_adcode',
                // width: 120,
                editable: true
            },
            {
                label: 'area_adname',
                name: 'area_adname',
                // width: 120,
                editable: true
            },
            {
                label: 'area_source',
                name: 'area_source',
                // width: 120,
                editable: true
            },
            {
                label: 'area_update_time',
                name: 'area_update_time',
                // width: 120,
                editable: false
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


