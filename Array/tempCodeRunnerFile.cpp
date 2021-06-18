
    int i=0;
    while(i<n)
    {
        if(a[i]<b[0])
        i++;

        else if(a[i]>=b[0])
        {
            if(a[i]==b[0])
            i++;
            int temp=a[n-1];
            for(int k=n-1;k>i;k--)
            {
                a[k]=a[k-1];
            }
            a[i]=b[0];
            int k=0;
            while((b[k+1]<temp)&&k<m)
            {
                b[k]=b[k+1];
                k++;
            }
            b[k]=temp;
            i++;
        }
    }