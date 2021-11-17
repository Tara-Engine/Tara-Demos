<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.5" tiledversion="1.7.2" name="Tileset_Terrain" tilewidth="16" tileheight="16" tilecount="32" columns="8">
 <image source="Tilemap_Terrain.png" width="128" height="64"/>
 <wangsets>
  <wangset name="Ground" type="corner" tile="-1">
   <wangcolor name="Grass" color="#ff0000" tile="-1" probability="1"/>
   <wangcolor name="Dirt" color="#00ff00" tile="-1" probability="1"/>
   <wangtile tileid="0" wangid="0,0,0,1,0,0,0,0"/>
   <wangtile tileid="1" wangid="0,0,0,1,0,1,0,0"/>
   <wangtile tileid="2" wangid="0,0,0,0,0,1,0,0"/>
   <wangtile tileid="3" wangid="0,0,0,2,0,0,0,0"/>
   <wangtile tileid="4" wangid="0,0,0,2,0,2,0,0"/>
   <wangtile tileid="5" wangid="0,0,0,0,0,2,0,0"/>
   <wangtile tileid="8" wangid="0,1,0,1,0,0,0,0"/>
   <wangtile tileid="9" wangid="0,1,0,1,0,1,0,1"/>
   <wangtile tileid="10" wangid="0,0,0,0,0,1,0,1"/>
   <wangtile tileid="11" wangid="0,2,0,2,0,0,0,0"/>
   <wangtile tileid="12" wangid="0,2,0,2,0,2,0,2"/>
   <wangtile tileid="13" wangid="0,0,0,0,0,2,0,2"/>
   <wangtile tileid="16" wangid="0,1,0,0,0,0,0,0"/>
   <wangtile tileid="17" wangid="0,1,0,0,0,0,0,1"/>
   <wangtile tileid="18" wangid="0,0,0,0,0,0,0,1"/>
   <wangtile tileid="19" wangid="0,2,0,0,0,0,0,0"/>
   <wangtile tileid="20" wangid="0,2,0,0,0,0,0,2"/>
   <wangtile tileid="21" wangid="0,0,0,0,0,0,0,2"/>
  </wangset>
  <wangset name="Walls" type="edge" tile="-1">
   <wangcolor name="Grey" color="#ff0000" tile="-1" probability="1"/>
   <wangtile tileid="6" wangid="0,0,1,0,1,0,0,0"/>
   <wangtile tileid="7" wangid="0,0,0,0,1,0,1,0"/>
   <wangtile tileid="14" wangid="1,0,1,0,0,0,0,0"/>
   <wangtile tileid="15" wangid="1,0,0,0,0,0,1,0"/>
   <wangtile tileid="22" wangid="1,0,1,0,1,0,0,0"/>
   <wangtile tileid="23" wangid="0,0,1,0,1,0,1,0"/>
   <wangtile tileid="25" wangid="1,0,1,0,1,0,1,0"/>
   <wangtile tileid="26" wangid="0,0,0,0,0,0,1,0"/>
   <wangtile tileid="27" wangid="1,0,0,0,0,0,0,0"/>
   <wangtile tileid="28" wangid="0,0,1,0,0,0,0,0"/>
   <wangtile tileid="29" wangid="0,0,0,0,1,0,0,0"/>
   <wangtile tileid="30" wangid="1,0,1,0,0,0,1,0"/>
   <wangtile tileid="31" wangid="1,0,0,0,1,0,1,0"/>
  </wangset>
 </wangsets>
</tileset>
