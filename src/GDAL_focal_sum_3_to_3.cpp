



#include <iostream>
// Gdal includes that are needed for this tutorial
#include <gdal.h>
#include <gdal_priv.h>
#include <ogrsf_frmts.h>

#include <string>

#include "GDAL_focal_sum.h"


using namespace std;


void  focal_sum::GDAL_focal_sum_3_to_3(const char * input_file, const char * output_file) 
{
	
		// Lets open a Tif
		GDALDataset *poDataset;
		
		// Register all gdal drivers -- load every possible driver gdal has
		GDALAllRegister();

		// lets load a "dataset" which is gdal terminology for your data
		poDataset = (GDALDataset*) GDALOpen(input_file, GA_ReadOnly);

		// Get width and height of this dataset
		int ncols = GDALGetRasterXSize(poDataset);
		int nrows = GDALGetRasterYSize(poDataset);
		//cout << "Data size: " << width << " " << height << endl;
		
		// ravesh divome mohasebeye num row and num column
		//int num_row = poDataset->GetRasterBand(1)->GetYSize();
		//int num_colm = poDataset->GetRasterBand(1)->GetXSize();
		
	    //cout << "Data size: num_row and num_colm " << num_colm << " " <<  num_row  << endl;

		
		const char *formatTIFF = "GTiff";
		//char *filenameTIFF= "orignaltiff.tif";
		const char *output = output_file;        
		
		GDALDataset *pTiffDS;
		

		GDALDriver *pDriverTIFF;
	    pDriverTIFF = GetGDALDriverManager()->GetDriverByName(formatTIFF);

        pTiffDS = pDriverTIFF->Create(output_file, ncols, nrows, 1, GDT_Float32, NULL);

		
	  
	  
      float *rowNew = (float*) CPLMalloc(sizeof(float)*ncols);
      
	  float *rowOld_1 = (float*) CPLMalloc(sizeof(float)*ncols);
	  float *rowOld_main = (float*) CPLMalloc(sizeof(float)*ncols);
	  float *rowOld_2 = (float*) CPLMalloc(sizeof(float)*ncols);


      /* iterate through all pixels in 2D dBZ
      * reflectivity array and assign values into rowBuff
      * array. Then write each row into Geotiff object.
      */
	  

	  int noData = poDataset->GetRasterBand(1)->GetNoDataValue();

 
    for(int row=0; row<nrows; row++) 
	{
		
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row,ncols,1,rowOld_main,ncols,1,GDT_Float32,0,0);
		
		if (row==0) 
		{
			
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row+1,ncols,1,rowOld_1,ncols,1,GDT_Float32,0,0);
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row+2,ncols,1,rowOld_2,ncols,1,GDT_Float32,0,0);

		}
		else if (row==nrows-1)
		{
			
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row-1,ncols,1,rowOld_1,ncols,1,GDT_Float32,0,0);
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row-2,ncols,1,rowOld_2,ncols,1,GDT_Float32,0,0);
		
		}
		else
		{
			
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row-1,ncols,1,rowOld_1,ncols,1,GDT_Float32,0,0);
		poDataset->GetRasterBand(1)->RasterIO(GF_Read,0,row+1,ncols,1,rowOld_2,ncols,1,GDT_Float32,0,0);
		
		}
		
		//poDataset1->GetRasterBand(1)->RasterIO(GF_Read,0,row,ncols,1,rowOld_1,ncols,1,GDT_Float32,0,0);
        

        for(int col=0; col<ncols; col++) 
		{
         
		 
		 if (col==0)
		 {
		  
		  rowNew[col]=rowOld_main[col+2]+rowOld_main[col]+rowOld_main[col+1]+rowOld_1[col+2]+rowOld_1[col]+rowOld_1[col+1]+rowOld_2[col+2]+rowOld_2[col]+rowOld_2[col+1];
 
		 }
		 
         else if (col==ncols-1)
         {
          
		  rowNew[col]=rowOld_main[col-1]+rowOld_main[col]+rowOld_main[col-2]+rowOld_1[col-1]+rowOld_1[col]+rowOld_1[col-2]+rowOld_2[col-1]+rowOld_2[col]+rowOld_2[col-2];
         }
		else
		{
		 
		 rowNew[col]=rowOld_main[col-1]+rowOld_main[col]+rowOld_main[col+1]+rowOld_1[col-1]+rowOld_1[col]+rowOld_1[col+1]+rowOld_2[col-1]+rowOld_2[col]+rowOld_2[col+1];
		}			 
		 
        }
		
        pTiffDS->GetRasterBand(1)->RasterIO(GF_Write,0,row,ncols,1,rowNew,ncols,1,GDT_Float32,0,0);
    }


   
   CPLFree(rowNew);
   
   CPLFree(rowOld_1);
   CPLFree(rowOld_main);
   CPLFree(rowOld_2);


   GDALClose(poDataset);
   GDALClose(pTiffDS);
   
   GDALDestroyDriverManager();


   //return 0;
	
}



        		