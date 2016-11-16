angular.module('myApp')
    .controller('userCtrl', function($rootScope, $scope){

        // var editor; // use a global for the submit and return data rendering in the examples

var url = 'http://11.239.171.218/admin/user/'

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
                label : 'login_time',
                name: 'login_time',
                // width: 140,
                editable: false 
            },
            {
                label : 'create_time',
                name: 'create_time',
                // width: 140,
                editable: false
            },
            {
                label : 'buc_userid',
                name: 'buc_userid',
                // width: 140,
                editable: true 
            },
            {
                label: 'empid',
                name: 'empid',
                // width: 100,
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


