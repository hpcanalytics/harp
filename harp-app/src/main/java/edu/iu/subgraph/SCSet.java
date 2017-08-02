/*
 * Copyright 2013-2017 Indiana University
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package edu.iu.subgraph;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

import edu.iu.harp.resource.Writable;

public class SCSet extends Writable {

  private int v_num;
  private int counts_num;

  // array to hold colorset ids for counts
  private int[] v_offset;
  private int[] counts_idx;
  private float[] counts_data;


  public SCSet() {

      v_num = -1;
      counts_num = -1;

      v_offset = new int[SCConstants.ARR_LEN];
      counts_idx = new int[SCConstants.ARR_LEN] ;
      counts_data = new float[SCConstants.ARR_LEN];
  }

  public SCSet(int v_num, int counts_num, 
          int[] v_offset, 
          int[] counts_idx, 
          float[] counts_data) {

      this.v_num = v_num;
      this.counts_num = counts_num;
      this.v_offset = v_offset;
      this.counts_idx = counts_idx;
      this.counts_data = counts_data;
  }

  @Override
  public int getNumWriteBytes() {
    return 8 + 4*(v_num+1) + 8*counts_num;
  }

  @Override
  public void write(DataOutput out)
    throws IOException {
    out.writeInt(v_num);
    out.writeInt(counts_num);

    for (int i = 0; i < v_num+1; i++) {
      out.writeInt(v_offset[i]);
    }
    for (int i = 0; i < counts_num; i++) {
        out.writeInt(counts_idx[i]);
    }
    for (int i = 0; i < counts_num; i++) {
      out.writeFloat(counts_data[i]);
    }

  }

  @Override
  public void read(DataInput in)
    throws IOException {
    v_num = in.readInt();
    counts_num = in.readInt();

    if (v_offset.length < (v_num + 1))
        v_offset = new int[v_num+1];

    if (counts_idx.length < counts_num)
    {
        counts_idx = new int[counts_num];
        counts_data = new float[counts_num];
    }

    for (int i = 0; i < v_num+1; i++) {
      v_offset[i] = in.readInt();
    }
    for (int i = 0; i < counts_num; i++) {
      counts_idx[i] = in.readInt();
    }
    for (int i = 0; i < counts_num; i++) {
      counts_data[i] = in.readFloat();
    }

  }

  @Override
  public void clear() {
      v_num = -1;
      counts_num = -1;
  }

  public int get_v_num() {
      return v_num;
  }

  public int get_counts_num(){
      return counts_num;
  }

  public int[] get_v_offset(){
      return v_offset;
  }

  public int[] get_counts_idx(){
      return counts_idx;
  }

  public float[] get_counts_data(){
      return counts_data;
  }
}